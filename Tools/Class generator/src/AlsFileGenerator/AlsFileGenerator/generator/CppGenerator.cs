using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator.generator
{
  class CppGenerator : SourceGenerator
  {
    public override void Generate(descriptor.AlsClassDescriptor classDescriptor_, string fileName_)
    {
      StringBuilder strGenerated = new StringBuilder();

      #region Generate includes
      strGenerated.AppendLine("//ABLETON");
      strGenerated.AppendFormat(ABLETON_INCLUDE, classDescriptor_.ClassName.ToLower());
      strGenerated.AppendLine();
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
      {
        strGenerated.AppendFormat(ABLETON_INCLUDE, cxAttr.Type.ToLower());
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        strGenerated.AppendFormat(ABLETON_INCLUDE, lstAttr.Type.ToLower());
        strGenerated.AppendLine();
        foreach (var possibleValue in lstAttr.PossibleContent)
        {
          strGenerated.AppendFormat(ABLETON_INCLUDE, possibleValue.Type.ToLower());
          strGenerated.AppendLine();
        }
      }
      strGenerated.AppendLine();
      #endregion

      #region Generate namespace
      strGenerated.AppendLine(NAMESPACE_MACRO_BEGIN);
      strGenerated.AppendLine();
      strGenerated.AppendLine();
      #endregion

      #region Constructor
      strGenerated.AppendFormat("{0}::{0}(QObject *parent)", classDescriptor_.ClassName);
      strGenerated.AppendLine();
      if (!String.IsNullOrEmpty(classDescriptor_.InheritFrom))
      {
        strGenerated.AppendFormat(": {0}(parent)", classDescriptor_.InheritFrom);
        strGenerated.AppendLine();
      }
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        try
        {          
          strGenerated.AppendFormat(", {0}({1})",
            smplAttr.AttributeName, TYPE_INITIALIZATION[smplAttr.Type]);
          strGenerated.AppendLine();
        }
        catch (KeyNotFoundException)
        {
          Console.WriteLine("Error trying to initialize type {0}, this type is not declared", 
            smplAttr.Type);
        }
      }
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
      {
        strGenerated.AppendFormat(", {0}(QSharedPointer<{1}>())", cxAttr.AttributeName, cxAttr.Type);
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        strGenerated.AppendFormat(", {0}(QVector<QSharedPointer<{1}>>())", 
          lstAttr.AttributeName, lstAttr.Type);
        strGenerated.AppendLine();
      }
      strGenerated.AppendLine("{");
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("_classManipulator = decltype(_classManipulator){");
      bool firstLine = true;
      //Simple attributes lambda
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        if (firstLine)
        {          
          firstLine = false;
        }
        else
        {
          strGenerated.AppendLine(",");
        }
        AppendIndent(ref strGenerated, 2);
        strGenerated.AppendFormat("{{ \"{0}\", qMakePair(nullptr, static_cast<SetVarLambda>(&{1}::set{2})) }}", 
          smplAttr.TagName, classDescriptor_.ClassName, smplAttr.AttributeName);
      }
      //Complex attributes lambda
      foreach(var cmplxAttr in classDescriptor_.ComplexAttributes)
      {
        if (firstLine)
        {
          firstLine = false;
        }
        else
        {
          strGenerated.AppendLine(",");
        }
        AppendIndent(ref strGenerated, 2);
        strGenerated.AppendFormat("{{ \"{0}\", qMakePair(static_cast<CreateVarLambda>(&{1}::create{2})), nullptr }}", 
          cmplxAttr.TagName, classDescriptor_.ClassName, cmplxAttr.AttributeName);
      }
      //List attributes lambda
      foreach(var lstAttr in classDescriptor_.ListAttributes)
      {
        if (firstLine)
        {
          firstLine = false;
        }
        else
        {
          strGenerated.AppendLine(",");
        }
        AppendIndent(ref strGenerated, 2);
        strGenerated.AppendFormat("{{ \"{0}\", qMakePair(static_cast<CreateVarLambda>(&{1}::create{2})), nullptr }}", 
          lstAttr.TagName, classDescriptor_.ClassName, lstAttr.AttributeName);

        foreach (var item in lstAttr.PossibleContent)
        {
          if (firstLine)
          {
            firstLine = false;
          }
          else
          {
            strGenerated.AppendLine(",");
          }
          AppendIndent(ref strGenerated, 2);
          strGenerated.AppendFormat("{{ \"{0}\", qMakePair(static_cast<CreateVarLambda>(&{1}::create{2})), nullptr }}", 
            item.TagName, classDescriptor_.ClassName, item.TagName);          
        }
      }
      strGenerated.AppendLine();
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("};");
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendFormat("_tagName = \"{0}\";", classDescriptor_.TagName);
      strGenerated.AppendLine();
      strGenerated.AppendLine("}");
      #endregion Constructor

      strGenerated.AppendLine();

      #region Write methods      
      strGenerated.AppendFormat("void {0}::write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)",
        classDescriptor_.ClassName);
      strGenerated.AppendLine();
      strGenerated.AppendLine("{");
      var xmlTagAttributes = classDescriptor_.SimpleAttributes.Where(x => x.IsXmlAttribute);
      String xmlTagAttr;
      if (xmlTagAttributes.Count() == 0)
      {
        xmlTagAttr = "QList<QPair<QString, QString>>()";
      }
      else
      {
        xmlTagAttr = "{";
        bool firstItem = false;
        foreach (var item in xmlTagAttributes)
        {
          if (firstItem)
          {
            firstItem = false;
          }
          else
          {
            xmlTagAttr += ",";
          }
          xmlTagAttr += String.Format("{{\"{0}\", {1}}}", 
            item.TagName, CONVERSION_TYPE_TO_STRING[item.Type]);
        }
        xmlTagAttr += "}";
      }
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendFormat("writeStartTag(p_fos_, _tagName, {0}, r_indentLvl_);", xmlTagAttr);
      strGenerated.AppendLine();
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("++r_indentLvl_;");
      if (!String.IsNullOrEmpty(classDescriptor_.InheritFrom))
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0}::writeInterface(p_fos_, r_indentLvl_);", 
          classDescriptor_.InheritFrom);
        strGenerated.AppendLine();
      }
      foreach (var smplAttr in classDescriptor_.SimpleAttributes.Where(x => !x.IsXmlAttribute))
      {
        AppendIndent(ref strGenerated, 1);
        if (CONVERSION_TYPE_TO_STRING.ContainsKey(smplAttr.Type))
        {
          strGenerated.AppendFormat("writeInlineTag(p_fos_,\"{0}\", {{{{\"Value\",",
            smplAttr.TagName);
          strGenerated.AppendFormat(CONVERSION_TYPE_TO_STRING[smplAttr.Type], smplAttr.AttributeName);
          strGenerated.Append("}}, r_indentLvl_);");
        }
        else
        {
          strGenerated.AppendFormat("//TODO: implement write tag {0}", smplAttr.AttributeName);
        }
        strGenerated.AppendLine();
      }
      foreach (var cmplxAttr in classDescriptor_.ComplexAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0}->write(p_fos_,r_indentLvl_);", cmplxAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var lst in classDescriptor_.ListAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("writeStartTag(p_fos_, \"{0}\", QList<QPair<QString,QString>>(), r_indentLvl_);",
          lst.TagName);
        strGenerated.AppendLine();
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendLine("++r_indentLvl_;");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("for(auto &item : {0}) {{", lst.AttributeName);
        strGenerated.AppendLine();
        AppendIndent(ref strGenerated, 2);
        strGenerated.AppendLine("item->write(p_fos_, r_indentLvl_);");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendLine("}");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendLine("--r_indentLvl_;");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("writeEndTag(p_fos_,\"Tracks\",r_indentLvl_);", lst.TagName);
        strGenerated.AppendLine();
      }
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("writeGarbage(p_fos_);");
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("--r_indentLvl_;");
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("writeEndTag(p_fos_, _tagName, r_indentLvl_);");
      
      strGenerated.AppendLine("}");

      if (classDescriptor_.IsInterface)
      {
        strGenerated.AppendLine();
        strGenerated.AppendFormat("void {0}::writeInterface(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_)",
       classDescriptor_.ClassName);
        strGenerated.AppendLine();
        strGenerated.AppendLine("{");
        foreach (var smplAttr in classDescriptor_.SimpleAttributes.Where(x => !x.IsXmlAttribute))
        {
          AppendIndent(ref strGenerated, 1);
          if (CONVERSION_TYPE_TO_STRING.ContainsKey(smplAttr.Type))
          {
            strGenerated.AppendFormat("writeInlineTag(p_fos_,\"{0}\", {{{{\"Value\",",
              smplAttr.TagName);
            strGenerated.AppendFormat(CONVERSION_TYPE_TO_STRING[smplAttr.Type], smplAttr.AttributeName);
            strGenerated.AppendLine("}}}}, r_indentLvl_);");
          }
          else
          {
            strGenerated.AppendFormat("//TODO: implement write tag {0}", smplAttr.AttributeName);
          }
          strGenerated.AppendLine();
        }
        foreach (var cplxAttr in classDescriptor_.ComplexAttributes)
        {
          strGenerated.AppendFormat("{0}->write(p_fos_,r_indentLvl_);",
            cplxAttr.AttributeName);
          strGenerated.AppendLine();
        }
        strGenerated.AppendLine("}");
      }
      #endregion Write method

      strGenerated.AppendLine();

      #region Set simple attributes methods
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        strGenerated.AppendFormat("void {0}::set{1}(const QString& value_)",
          classDescriptor_.ClassName, smplAttr.AttributeName);
        strGenerated.AppendLine();
        strGenerated.AppendLine("{");
        AppendIndent(ref strGenerated, 1);
        if (CONVERSION_TYPE_FROM_STRING.ContainsKey(smplAttr.Type))
        {
          strGenerated.AppendFormat(CONVERSION_TYPE_FROM_STRING[smplAttr.Type], smplAttr.AttributeName, "value_");
        }
        else
        {
          strGenerated.Append("//TODO: Manually set variable");
        }
        strGenerated.AppendLine();
        strGenerated.AppendLine("}");

        strGenerated.AppendLine();
      }
      #endregion

      #region Create complex attributes methods
      foreach (var cplxAttr in classDescriptor_.ComplexAttributes)
      {
        strGenerated.AppendFormat("QSharedPointer<QObject> {0}::create{1}()",
          classDescriptor_.ClassName, cplxAttr.AttributeName);
        strGenerated.AppendLine();
        strGenerated.AppendLine("{");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0} = QSharedPointer<{1}>(new {1}(this));",
          cplxAttr.AttributeName,cplxAttr.Type);
        strGenerated.AppendLine();
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("return {0}.staticCast<QObject>();",
          cplxAttr.AttributeName);
        strGenerated.AppendLine();
        strGenerated.AppendLine("}");
        strGenerated.AppendLine();
      }
      #endregion

      #region Create list attributes methods
      foreach (var lst in classDescriptor_.ListAttributes)
      {
        strGenerated.AppendFormat("QSharedPointer<QObject> {0}::create{1}()",
          classDescriptor_.ClassName, lst.AttributeName);
        strGenerated.AppendLine();
        strGenerated.AppendLine("{");
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0}.clear();", lst.AttributeName);
        strGenerated.AppendLine();
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendLine("return QSharedPointer<QObject>();");
        strGenerated.AppendLine("}");
        strGenerated.AppendLine();

        foreach (var item in lst.PossibleContent)
        {
          strGenerated.AppendFormat("QSharedPointer<QObject> {0}::create{1}()",
          classDescriptor_.ClassName, item.TagName);
          strGenerated.AppendLine();
          strGenerated.AppendLine("{");
          AppendIndent(ref strGenerated, 1);
          strGenerated.AppendFormat("auto item = QSharedPointer<{0}>(new {0}(this));", 
            item.Type);
          strGenerated.AppendLine();
          AppendIndent(ref strGenerated, 1);
          strGenerated.AppendFormat("{0}.push_back(item);", lst.AttributeName);
          strGenerated.AppendLine();
          AppendIndent(ref strGenerated, 1);
          strGenerated.AppendLine("return item.staticCast<QObject>();");
          strGenerated.AppendLine("}");
          strGenerated.AppendLine();
        }
      }
      #endregion

      #region Destructor
      strGenerated.AppendFormat("{0}::~{0}()", classDescriptor_.ClassName);
      strGenerated.AppendLine();
      strGenerated.AppendLine("{");
      strGenerated.AppendLine();
      strGenerated.AppendLine("}");
      #endregion

      strGenerated.AppendLine();
      strGenerated.AppendLine(NAMESPACE_MACRO_END);

      using (var rs = new StreamWriter(fileName_))
      {
        rs.Write(strGenerated.ToString());
      }
    }
  }//End class
}
