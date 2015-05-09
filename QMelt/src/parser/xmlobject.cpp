#include "src/parser/xmlobject.h"

#include "src/io/alsfilestreambase.h"

namespace parser {

  XMLObject::XMLObject(QObject *parent) : QObject(parent)
  {

  }

  void XMLObject::writeStartTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                                const QList<QPair<QString,QString>> &r_attributes_, int &r_indentLvl_)
  {
    writeNewLine(p_fos_);
    writeIndent(p_fos_, r_indentLvl_);
    QString tag("<");
    tag += r_tagName_;
    auto qi = r_attributes_.constBegin();
    while (qi != r_attributes_.constEnd())
    {
      tag += " ";
      tag += qi->first;
      tag += "=\"";
      tag += qi->second;
      tag += "\"";
      ++qi;
    }
    tag += ">";
    p_fos_->write(tag);
  }


  void XMLObject::writeInlineTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                                 const QList<QPair<QString,QString>> &r_attributes_, int &r_indentLvl_)
  {    
    writeNewLine(p_fos_);
    writeIndent(p_fos_, r_indentLvl_);
    QString tag("<");
    tag += r_tagName_;
    auto qi = r_attributes_.constBegin();
    while (qi != r_attributes_.constEnd())
    {
      tag += " ";
      tag += qi->first;
      tag += "=\"";
      tag += qi->second;
      tag += "\"";
      ++qi;
    }
    tag += "/>";
    p_fos_->write(tag);
  }


  void XMLObject::writeEndTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                              int &r_indentLvl_)
  {    
    writeNewLine(p_fos_);
    writeIndent(p_fos_, r_indentLvl_);
    QString tag("</");
    tag += r_tagName_;
    tag += ">";
    p_fos_->write(tag);
  }


  void XMLObject::writeIndent(QSharedPointer<io::AlsFileStreamBase> p_fos_, int idt_)
  {
    for (int i = 0; i < idt_; ++i) {
      p_fos_->write("\t");
    }
  }

  void XMLObject::writeNewLine(QSharedPointer<io::AlsFileStreamBase> p_fos_)
  {
    p_fos_->write("\n");
  }

  void XMLObject::writeGarbage(QSharedPointer<io::AlsFileStreamBase> p_fos_)
  {
    p_fos_->write(_garbage);
  }

  bool XMLObject::canCreateVar(const QString &r_varName_)
  {
    return (this->_classManipulator.contains(r_varName_));
  }

  QSharedPointer<QObject> XMLObject::createVar(const QString &r_varName_)
  {
    CreateVarLambda cvl = this->_classManipulator[r_varName_].first;
    return ((this->*cvl)());
  }

  void XMLObject::setVar(const QString &r_varName_, const QString &r_value_)
  {
    if (this->_classManipulator.contains(r_varName_))
    {
      SetVarLambda svl = this->_classManipulator[r_varName_].second;
      (this->*svl)(r_value_);
    }
  }

  void XMLObject::appendGarbage(const QString &text_)
  {    
    _garbage.append("\n");
    _garbage.append(text_);
  }

}//namespace parser

