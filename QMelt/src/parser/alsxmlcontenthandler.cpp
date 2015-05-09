#include "src/parser/alsxmlcontenthandler.h"

#include <QDebug>


namespace parser
{
  AlsXMLContentHandler::AlsXMLContentHandler()
  : _currTagNotProcessed(false)
  ,_ignoredTagCounter(0)
  {
  }

  void AlsXMLContentHandler::startDocument(XMLContext& r_ctx_, const QString& version_,
    const QString& encoding_)
  {

  }

  void AlsXMLContentHandler::startTag(XMLContext& r_ctx_, const QString& r_tagName_,
    const QHash<QString, QString> &r_attributes_,
    const QString& r_line_)
  {
    QSharedPointer<parser::XMLObject> currentObject = r_ctx_.Stack().last().staticCast<parser::XMLObject>();

    if (_currTagNotProcessed)
    {
      if(r_tagName_ == r_ctx_.CurrentTag())
      {
        ++_ignoredTagCounter;
      }
      currentObject->appendGarbage(r_line_);
      return;
    }

    r_ctx_.CurrentTag(r_tagName_);

    if (currentObject->canCreateVar(r_tagName_))
    {
      QSharedPointer<QObject> objectCreated = currentObject->createVar(r_tagName_);
      if (objectCreated != nullptr)
      {
        if (!r_attributes_.empty())
        {
          QSharedPointer<parser::XMLObject> xmlObjectCreated = objectCreated.staticCast<parser::XMLObject>();;
          auto qi = r_attributes_.constBegin();
          while (qi != r_attributes_.constEnd())
          {
            xmlObjectCreated->setVar(qi.key(), qi.value());
            ++qi;
          }
        }
        r_ctx_.pushToStack(objectCreated);
      }
    }
    else
    {
      _currTagNotProcessed = true;
      ++_ignoredTagCounter;
      currentObject->appendGarbage(r_line_);
    }
  }

  void AlsXMLContentHandler::inlineTag(XMLContext& r_ctx_, const QString &tagName_,
    const QHash<QString, QString>& r_attributes_,
    const QString& r_line_)
  {
    //Debug
    if(tagName_ == "Overdub")
    {
      qDebug() << tagName_;
    }

    QSharedPointer<parser::XMLObject> currentObject = r_ctx_.Stack().last().staticCast<parser::XMLObject>();

    if (_currTagNotProcessed || !currentObject->canCreateVar(tagName_))
    {
      currentObject->appendGarbage(r_line_);
      return;
    }

    if (!r_attributes_.empty())
    {
      //Inline tag with only one arg --> simple attribute
      if (r_attributes_.size() == 1)
      {
        currentObject->setVar(tagName_, r_attributes_.begin().value());
      }
      else
      {
        QSharedPointer<parser::XMLObject> xmlObjectCreated = currentObject->createVar(tagName_).staticCast<parser::XMLObject>();
        auto qi = r_attributes_.constBegin();
        while (qi != r_attributes_.constEnd())
        {
          xmlObjectCreated->setVar(qi.key(), qi.value());
          ++qi;
        }
      }
    }
  }

  void AlsXMLContentHandler::characters(XMLContext& r_ctx_, const QString& r_data_)
  {
    QSharedPointer<parser::XMLObject> currentObject = r_ctx_.Stack().last().staticCast<parser::XMLObject>();

    if (_currTagNotProcessed)
    {
      currentObject->appendGarbage(r_data_);
      return;
    }

    r_ctx_.appendData(r_data_.trimmed());
  }

  void AlsXMLContentHandler::endTag(XMLContext& r_ctx_, const QString& r_tagName_,
    const QString& r_line_)
  {
    QSharedPointer<parser::XMLObject> currentObject = r_ctx_.Stack().last().staticCast<parser::XMLObject>();

    if (!_currTagNotProcessed)//Tag is processed
    {
      if (!r_ctx_.CurrentData().isEmpty())
      {
        *(r_ctx_.Stack().last().dynamicCast<QString>()) = r_ctx_.CurrentData();
        r_ctx_.eraseData();
      }
      if ( QString::compare(r_tagName_, currentObject->TagName(), Qt::CaseInsensitive) == 0) {
        r_ctx_.popStack();
      }
    }
    else if(r_ctx_.CurrentTag() == r_tagName_){ //End of data not processed
      currentObject->appendGarbage(r_line_);
      --_ignoredTagCounter;
      if(_ignoredTagCounter <= 0)
      {
        _currTagNotProcessed = false;
        _ignoredTagCounter = 0; //For safety
      }
    }
    else
    {
      currentObject->appendGarbage(r_line_);
    }

  }
}
