using AlsFileGenerator.descriptor;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator.generator
{
  public abstract class SourceGenerator
  {
    public const String INDENT = "  ";
    public const String ABLETON_INCLUDE = "#include \"src/ableton/{0}.h\"";
    public const String NAMESPACE_MACRO_BEGIN = "M_NAMESPACE_ABLETON_BEGIN";
    public const String NAMESPACE_MACRO_END = "M_NAMESPACE_ABLETON_END";

    public readonly Dictionary<String, String> TYPE_INITIALIZATION = new Dictionary<string, string>(){
      {"int","0"},
      {"double","0.0"},
      {"float","0.0"},
      {"QString","\"\""},
      {"bool","false"},
      {"long","0"}
    };

    public readonly Dictionary<String, String> CONVERSION_TYPE_FROM_STRING = new Dictionary<string, string>{
      {"int","{0} = {1}.toInt();"},
      {"double", "{0} = {1}.toDouble();"},
      {"long", "{0} = {1}.toLong();"},
      {"float", "{0} = {1}.toFloat();"},
      {"short", "{0} = {1}.toShort();"},
      {"QString", "{0} = QString({1});"},
      {"bool", "{0} = ({1}.toLower().trimmed() == \"true\" ? true : false);"}
    };

    public readonly Dictionary<String, String> CONVERSION_TYPE_TO_STRING = new Dictionary<string, string>{
      {"int","QString::number({0})"},
      {"double", "QString::number({0})"},
      {"long", "QString::number({0})"},
      {"float", "QString::number({0})"},
      {"short", "QString::number({0})"},
      {"QString", "{0}"},
      {"bool", "{0} ? \"true\" : \"false\""}
    };

    public abstract void Generate(AlsClassDescriptor classDescriptor_, String fileName_);

    protected void AppendIndent(ref StringBuilder sb_,int indentLvl_)
    {
      for (int i = 0; i < indentLvl_; i++)
			{
			 sb_.Append(INDENT);
			}
    }
  }
}
