#pragma once
#include "src/common/common.h"


// QT
#include <QObject>
#include <QString>


M_NAMESPACE_IO_BEGIN


  /*!
 * \brief The base class to read ALS files
 */
class AlsFileStreamBase : public QObject
{
  Q_OBJECT
public:
  /*!
   * \brief Destructor
   */
  virtual ~AlsFileStreamBase() {}

  /*!
   * \return True if the stream doesn't have anymore data
   */
  virtual bool isExhausted() = 0;

  /*!
   * \return True if the stream is correctly opened
   */
  virtual bool isOk() = 0;

  /*!
   * \brief Reads the next line of the ALS file and moves
   * the position in the stream
   * \return A string containing the current line
   */
  virtual QString readNextLine() = 0;

  /*!
   * \brief Write the given data in the stream
   * \param dataToWrite_ The string that will be written
   */
  virtual void write(const QString & dataToWrite_) = 0;

protected:
  /*!
   * \brief Protected constructor
   * \param parent
   */
  AlsFileStreamBase(QObject *parent = 0) : QObject(parent) {}

private:
};


M_NAMESPACE_IO_END
