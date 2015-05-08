#pragma once

// APP
#include "src/app/meltapplication.h"

// QT
#include <QObject>
#include <QString>
#include <QSharedPointer>


namespace app
{

  /*!
 * \brief Command line argument structure, can also parse QApplication args
 */
class MeltCommandLine : public QObject
{
  Q_OBJECT
public:
  /*!
   * \brief Command line parser
   * Here are a few examples
   *
   * DIFF:
   * QMelt -d --local /Path/To/File --remote /Path/To/File
   * MERGING:
   * QMelt -m --base /Path/To/File --local /Path/To/File --remote /Path/To/File --merge /Path/To/File
   *
   * Caution : if wrong argument are found, the application will stop
   * \param app_ The application that should be parsed
   * \return A shared pointer containing all the valid parsed arguments
   */
  static QSharedPointer<MeltCommandLine> parse(const MeltApplication& app_);

  /*!
   * \brief Path to base file
   */
  QString basePath;
  /*!
   * \brief Path to local file
   */
  QString localPath;
  /*!
   * \brief Path to remote file
   */
  QString remotePath;
  /*!
   * \brief Path to merge file
   */
  QString mergePath;

  /*!
   * \brief True if the parsed arguments are valid
   */
  bool isOk;
  /*!
   * \brief True if a merge is requested
   */
  bool isMerging;

protected:
  /*!
   * \brief Protected constructor
   * \param parent
   */
  explicit MeltCommandLine(QObject *parent = 0) : QObject(parent) {}
};


} // namespace app
