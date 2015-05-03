#include "xml_object.h"

namespace parser {

  XMLObject::XMLObject(QObject *parent) : QObject(parent)
  {

  }

  void XMLObject::writeStartTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                                const QHash<QString, QString> &r_attributes_, int &r_indentLvl_)
  {
    //TODO implements method
  }


  void XMLObject::writeInlineTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                                 const QHash<QString, QString> &r_attributes_, int &r_indentLvl_)
  {
    //TODO implement method
  }


  void XMLObject::writeEndTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                              int &r_indentLvl_)
  {
    //TODO implement method
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
    _garbage.append(text_);
  }

}//namespace parser

