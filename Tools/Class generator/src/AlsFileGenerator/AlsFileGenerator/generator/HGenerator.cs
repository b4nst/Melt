using AlsFileGenerator.descriptor;
using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AlsFileGenerator.generator
{
  public class HGenerator : SourceGenerator
  {
    public override void Generate(AlsClassDescriptor classDescriptor_, String fileName_)
    {
      StringBuilder strGenerated = new StringBuilder();
      strGenerated.AppendLine("#pragma once");
      strGenerated.AppendLine();

      if (!String.IsNullOrEmpty(classDescriptor_.InheritFrom))
      {
        strGenerated.AppendLine("// ABLETON");
        strGenerated.AppendFormat(ABLETON_INCLUDE, classDescriptor_.InheritFrom.ToLower());
        strGenerated.AppendLine();
        strGenerated.AppendLine();
      }

      if(classDescriptor_.ListAttributes.Count > 0)
      {
        strGenerated.AppendLine("// QT");
        strGenerated.AppendLine("#include <QList>");
        strGenerated.AppendLine();
      }

      //Forward declaration
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
	    {
        strGenerated.AppendFormat("M_FORWARD_ABLETON({0})", cxAttr.Type);
        strGenerated.AppendLine();
	    }
      strGenerated.AppendLine();

      //Namespace
      strGenerated.AppendLine(NAMESPACE_MACRO_BEGIN);
      strGenerated.AppendLine();

      //Class
      strGenerated.AppendFormat("class {0}", classDescriptor_.ClassName);
      if (!String.IsNullOrEmpty(classDescriptor_.InheritFrom))
      {
        strGenerated.AppendFormat(" : public {0}", classDescriptor_.InheritFrom);
      }
      strGenerated.AppendLine();
      strGenerated.AppendLine("{");

      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("Q_OBJECT");
      strGenerated.AppendLine("public:");

      //Constructor destructor
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendFormat("{0}(QObject* parent);", classDescriptor_.ClassName);
      strGenerated.AppendLine();
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendFormat("~{0}();", classDescriptor_.ClassName);
      strGenerated.AppendLine();
      strGenerated.AppendLine();

      //Write method
      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);");
      strGenerated.AppendLine();

      AppendIndent(ref strGenerated, 1);
      strGenerated.AppendLine("virtual void writeInterface(QSharedPointer<io::AlsFileStreamBase> p_fos_, int& r_indentLvl_);");
      strGenerated.AppendLine();

      //Set methods
      strGenerated.AppendLine("// Set var lambda");
      foreach (var sAttr in classDescriptor_.SimpleAttributes)
      {
        AppendIndent(ref strGenerated,1);
        strGenerated.AppendFormat("void set{0}(const QString &r_value_);",sAttr.AttributeName);
        strGenerated.AppendLine();
      }
      strGenerated.AppendLine();

      //Create methods
      strGenerated.AppendLine("// Create var lambda");
      foreach (var cpxAttr in classDescriptor_.ComplexAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("QSharedPointer<QObject> create{0}();", cpxAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("QSharedPointer<QObject> create{0}();", lstAttr.AttributeName);
        strGenerated.AppendLine();
        foreach (var possibleValue in lstAttr.PossibleContent)
        {
          AppendIndent(ref strGenerated, 1);
          strGenerated.AppendFormat("QSharedPointer<QObject> create{0}();", possibleValue.TagName);
          strGenerated.AppendLine();
        }
      }
      strGenerated.AppendLine();

      //Attributes
      strGenerated.AppendLine("// Class attributes");
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0} {1};", smplAttr.Type, smplAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("{0} {1};", cxAttr.Type, cxAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("QList<QSharedPointer<{0}>> {1};", lstAttr.Type, lstAttr.AttributeName);
        strGenerated.AppendLine();
      }
      strGenerated.AppendLine();

      //QProperties
      strGenerated.AppendLine("// QProperties");
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("Q_PROPERTY({0} {1} Member {1} NOTIFY {1}Changed)", smplAttr.Type, smplAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("Q_PROPERTY({0} {1} Member {1} NOTIFY {1}Changed)", cxAttr.Type, cxAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("Q_PROPERTY(QList<QSharedPointer<{0}>>({0} {1} Member {1} NOTIFY {1}Changed)", lstAttr.Type, lstAttr.AttributeName);
        strGenerated.AppendLine();
      }
      strGenerated.AppendLine();

      //Signals
      strGenerated.AppendLine("signals:");
      foreach (var smplAttr in classDescriptor_.SimpleAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("void {1}Changed();", smplAttr.Type, smplAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var cxAttr in classDescriptor_.ComplexAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("void {1}Changed();", cxAttr.Type, cxAttr.AttributeName);
        strGenerated.AppendLine();
      }
      foreach (var lstAttr in classDescriptor_.ListAttributes)
      {
        AppendIndent(ref strGenerated, 1);
        strGenerated.AppendFormat("void {1}Changed();"  , lstAttr.Type, lstAttr.AttributeName);
        strGenerated.AppendLine();
      }
      strGenerated.AppendLine();

      //End class
      strGenerated.AppendLine("};");
      strGenerated.AppendLine();
      strGenerated.AppendLine();
      strGenerated.AppendLine(NAMESPACE_MACRO_END);

      using (var rs = new StreamWriter(fileName_))
      {
        rs.Write(strGenerated.ToString());
      }
    }
  }
}
