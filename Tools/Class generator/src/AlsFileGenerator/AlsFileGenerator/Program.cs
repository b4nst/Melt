using AlsFileGenerator.descriptor;
using AlsFileGenerator.generator;
using CommandLine;
using CommandLine.Text;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace AlsFileGenerator
{
  class Program
  {
    class Options
    {
      [Option('i', "input", Required = true,
        HelpText = "Input directory to be processed.")]
      public string InputDir { get; set; }

      [Option('o', "output", Required = true,
        HelpText = "Output directory, where files will be generated.")]
      public string OutputDir { get; set; }

      [Option('v', "verbose", DefaultValue = true,
        HelpText = "Prints all messages to standard output.")]
      public bool Verbose { get; set; }

      [ParserState]
      public IParserState LastParserState { get; set; }

      [HelpOption]
      public string GetUsage()
      {
        return HelpText.AutoBuild(this,
          (HelpText current) => HelpText.DefaultParsingErrorsHandler(this, current));
      }
    }

    static void Main(string[] args)
    {
      var options = new Options();

      if (CommandLine.Parser.Default.ParseArguments(args, options))
      {
        DirectoryInfo inputDir = new DirectoryInfo(options.InputDir);
        if (!inputDir.Exists)
        {
          Console.ForegroundColor = ConsoleColor.Red;
          Console.WriteLine("Couldn't find input directory {0}", options.InputDir);
          Console.ForegroundColor = ConsoleColor.Gray;
          Environment.Exit(3);
        }

        DirectoryInfo outputDir = new DirectoryInfo(options.OutputDir);
        if (!outputDir.Exists)
        {
          if (options.Verbose)
          {
            Console.WriteLine("Creating output dir...");
          }
          outputDir.Create();
        }

        if (options.Verbose)
        {
          Console.WriteLine("Analyzing input ...");
        }

        int nbFiles = inputDir.GetFiles("*.xml").Length;

        if (options.Verbose)
        {
          Console.WriteLine("Found {0} file(s) to generate.", nbFiles);
          Console.WriteLine("Starting generation...");
        }


        AlsClassDescriptor als;
        XmlSerializer xs = new XmlSerializer(typeof(AlsClassDescriptor));
        Dictionary<FileInfo, Exception> errors = new Dictionary<FileInfo, Exception>();
        int currFile = 1;

        TextProgressBar progressBar = new TextProgressBar();
        progressBar.Size = 50;
        progressBar.MaxValue = nbFiles;
        progressBar.CurrentValue = 0;

        foreach (var file in inputDir.GetFiles("*.xml"))
        {
          progressBar.CurrentValue++;
          try
          {
            using (StreamReader rd = new StreamReader(file.FullName))
            {
              als = xs.Deserialize(rd) as AlsClassDescriptor;
            }
            HGenerator hGene = new HGenerator();
            CppGenerator cppGene = new CppGenerator();
            hGene.Generate(als, Path.Combine(options.OutputDir, als.ClassName.ToLower() + ".h"));
            cppGene.Generate(als, Path.Combine(options.OutputDir, als.ClassName.ToLower() + ".cpp"));
          }
          catch (Exception e)
          {
            errors.Add(file, e);
          }
          currFile++;
        }

        Console.WriteLine("");
        if (errors.Count > 0)
        {
          Console.ForegroundColor = ConsoleColor.Red;
          Console.WriteLine("The generator has encoutered error on the following files :");
          errors.ToList().ForEach(pair => Console.WriteLine("{0} error : {1}", pair.Key.FullName, pair.Value.Message));
          Console.ForegroundColor = ConsoleColor.Gray;
        }
        else
        {
          Console.ForegroundColor = ConsoleColor.Green;
          Console.WriteLine("Sucess.");
          Console.ForegroundColor = ConsoleColor.Gray;
        }
      }
    }
  }


}
