#pragma once

#include <QObject>
#include <QHash>
#include <QSharedPointer>

//forward declaration
namespace io { class AlsFileStreamBase; }

namespace parser {

/*!
* \brief
* Class XMLObject
* Base class for XML read objects.
*/
class XMLObject : public QObject
{
  Q_OBJECT
public:
  /*!
   * \brief XMLObject
   * Constructor
   * \param parent
   */
  explicit XMLObject(QObject *parent);

  /*!
   * \brief ~XMLObject
   * Destructor
   */
  virtual ~XMLObject() {}

  /*!
   * \brief writeStartTag
   * Write a start tag
   * \param p_fos_
   * The file stream to write in.
   * \param r_tagName_
   * The tag name
   * \param r_attributes_
   * The attributes to add in tag.
   * \param r_indentLvl_
   * The reference to the level of indentation.
   */
  void writeStartTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
      const QList<QPair<QString,QString>> &r_attributes_, int &r_indentLvl_);

  /*!
   * \brief writeInlineTag
   * Write an inline tag
   * \param p_fos_
   * The file stream to write in.
   * \param r_tagName_
   * The tag name
   * \param r_attributes_
   * The attributes to add in tag.
   * \param r_indentLvl_
   * The reference to the level of indentation.
   */
  void writeInlineTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
      const QList<QPair<QString,QString>> &r_attributes_, int &r_indentLvl_);

   /*!
    * \brief writeEndTag
    * Write an inline tag
    * \param p_fos_
    * The file stream to write in.
    * \param r_tagName_
    * The tag name
    * \param r_indentLvl_
    * The reference to the level of indentation.
    */
  void writeEndTag(QSharedPointer<io::AlsFileStreamBase> p_fos_, const QString &r_tagName_,
                     int &r_indentLvl_);

  /*!
   * \brief write
   * Write this XMLObject
   * \param p_fos_
   * The file stream to write in.
   * \param r_indentLvl_
   * The reference to the level of indentation.
   */
  virtual void write(QSharedPointer<io::AlsFileStreamBase> p_fos_, int &r_indentLvl_) = 0;

  void writeIndent(QSharedPointer<io::AlsFileStreamBase> p_fos_, int idt_);

  void writeNewLine(QSharedPointer<io::AlsFileStreamBase> p_fos_);

  void writeGarbage(QSharedPointer<io::AlsFileStreamBase> p_fos_);

  /*!
   * \brief canCreateVar
   * Determines whether this instance can create the specified variable varName_.
   * \param r_varName_
   * The variable name.
   * \return
   * True if can create.
   */
  bool canCreateVar(const QString &r_varName_);

  /*!
   * \brief createVar
   * Creates the variable varName_.
   * \param r_varName_
   * The variable name.
   * \return
   * A pointer to the created variable
   */
  QSharedPointer<QObject> createVar(const QString &r_varName_);

  /*!
   * \brief setVar
   * Sets the variable.
   * \param r_varName_
   * The variable name_.
   * \param r_value_
   * The value_.
   */
  void setVar(const QString &r_varName_, const QString &r_value_);

  void appendGarbage(const QString &text_);

  QString TagName(){return _tagName;}

protected:
  typedef QSharedPointer<QObject>(XMLObject::*CreateVarLambda)();
  typedef void(XMLObject::*SetVarLambda)(const QString&);

  QString _tagName;
  QString _garbage;

  QHash<QString, QPair<CreateVarLambda, SetVarLambda>> _classManipulator;

signals:

public slots:
};

}//namespace paser

