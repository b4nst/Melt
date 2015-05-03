#pragma once


// std

#include <QStack>


// parser

#include "src/parser/xmlobject.h"


namespace parser
{


/// <summary>
/// Class XMLContext
/// <para>Context usefull to parse a file. Contain stack of <see cref="XMLObject"/>, current tag, current data...</para>
/// </summary>
class XMLContext
{
public:
  XMLContext();
  ~XMLContext();

  const QStack<QSharedPointer<QObject>>& Stack(){ return _stack; }
  void pushToStack(QSharedPointer<QObject> object_){ _stack.push(object_); }
  void popStack(){ _stack.pop(); }

  void CurrentTag(const QString& tag_){ _currentTag = tag_; }
  const QString& CurrentTag(){ return _currentTag; }

  const QString& CurrentData() { return _currentData; }
  void appendData(const QString& data_){ _currentData.append(data_); }
  void eraseData(){ _currentData.clear(); }

private:
  /// <summary>
  /// Stack of <see cref="XMLObject"/> processed and not finished (endTag not yet reached).
  /// _stack[n-1] is the parent of _stack[n].
  /// </summary>
  QStack<QSharedPointer<QObject>> _stack;


  /// <summary>
  /// Last start tag reached by the parser.
  /// </summary>
  QString _currentTag;


  /// <summary>
  /// Current data read out of tag.
  /// </summary>
  QString _currentData;
};


} // namespace parser
