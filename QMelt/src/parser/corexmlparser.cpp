/*
  ==============================================================================

    CoreXMLParser.cpp
    Created: 11 Apr 2015 3:39:39pm
    Author:  Bastien

  ==============================================================================
*/

#include "src/parser/corexmlparser.h"
#include "src/io/alsfilestreambase.h"

#include <QRegularExpression>

#define INLINE_TAG_PATTERN "<(\\w+)([.\\d]*)(?: (?:\\w+)=\"(?:[^\"]*)\")* ?/>"
#define START_TAG_PATTERN "<(\\w+)([.\\d]*)(?: (?:(?:\\w+)=\"(?:[^\"]*)\"))* ?>"
#define END_TAG_PATTERN   "</(\\w+)([.\\d]*) ?>"
#define START_DOCUMENT_PATTERN  "<\\?xml version=\"([^\"]+)\" encoding=\"([^\"]+)\"\\?>"
#define ARGS_PATTERN  "(\\w+)=\"([^\"]*)\""

namespace parser
{
  void CoreXMLParser::parse(QSharedPointer<io::AlsFileStreamBase> p_stream_,
    XMLContentHandler& r_handler_, XMLContext& r_ctx_)
  {
    QString currLine;
    QRegularExpression rInline(INLINE_TAG_PATTERN);
    QRegularExpression rStart(START_TAG_PATTERN);
    QRegularExpression rEnd(END_TAG_PATTERN);
    QRegularExpression rDoc(START_DOCUMENT_PATTERN);
    QRegularExpressionMatch matches;
    QHash<QString, QString> args;

    while (!p_stream_->isExhausted())
    {
      currLine = p_stream_->readNextLine();

      //Tests against pattern
      if ((matches = rInline.match(currLine)).hasMatch())
      {
        findArgs(currLine, args);
        r_handler_.inlineTag(r_ctx_, matches.captured(1), args, currLine);
      }
      else if ((matches = rStart.match(currLine)).hasMatch())
      {
        findArgs(currLine, args);
        r_handler_.startTag(r_ctx_, matches.captured(1), args, currLine);
      }
      else if ((matches = rEnd.match(currLine)).hasMatch())
      {
        r_handler_.endTag(r_ctx_, matches.captured(1), currLine);
      }
      else if ((matches = rDoc.match(currLine)).hasMatch())
      {
        r_handler_.startDocument(r_ctx_, matches.captured(1), matches.captured(2));
      }
      else
      {
        r_handler_.characters(r_ctx_, currLine);
      }
    }
  }

  void CoreXMLParser::findArgs(QString str_, QHash<QString, QString>& args_)
  {
    QRegularExpression rArgs(ARGS_PATTERN);
    QRegularExpressionMatchIterator matchesIterator = rArgs.globalMatch(str_);

    args_.clear();
    while (matchesIterator.hasNext())
    {
      QRegularExpressionMatch match = matchesIterator.next();
      args_.insert( match.captured(1),  match.captured(2) );
    }
  }
}
