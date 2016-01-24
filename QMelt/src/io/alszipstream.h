#pragma once


// IO
#include "src/io/alsfilestreambase.h"


// QT
#include <QByteArray>
#include <QFile>


M_NAMESPACE_IO_BEGIN


/*!
 * \brief Zip stream implementation to read compressed ALS files
 */
class AlsZipStream : public AlsFileStreamBase
{
public:
  /*!
   * \brief Constructor
   * \param file_ The Zip file that will be read
   * \param parent
   */
  AlsZipStream(QFile &file_, QObject *parent = 0);

  /*!
   * \brief Destructor
   */
  ~AlsZipStream();

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
  QByteArray _array;
  QByteArray::iterator _it;
};


M_NAMESPACE_IO_END
