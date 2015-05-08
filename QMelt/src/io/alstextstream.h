#pragma once


// IO
#include "src/io/alsfilestreambase.h"


// QT
#include <QFile>
#include <QTextStream>


M_NAMESPACE_IO_BEGIN


/*!
 * \brief QTextStream implementation to read uncompressed ALS files
 */
class AlsTextStream : public AlsFileStreamBase
{
public:
  /*!
   * \brief Constructor
   * \param file_ The XML file that will be read
   * \param parent
   */
  AlsTextStream(QFile &file_, QObject *parent = 0);

  /*!
   * \brief Destructor
   */
  ~AlsTextStream();

  /*!
   * \see AlsFileStreamBase::isExhausted()
   */
  virtual bool isExhausted();

  /*!
   * \see AlsFileStreamBase::isOk()
   */
  virtual bool isOk();

  /*!
   * \see AlsFileStreamBase::readNextLine()
   */
  virtual QString readNextLine();

  /*!
   * \see AlsFileStreamBase::write()
   */
  virtual void write(const QString & string_);

private:
  /*!
   * \brief Stream to read the given file
   */
  QTextStream _stream;
};


M_NAMESPACE_IO_END
