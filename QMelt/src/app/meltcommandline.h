#pragma once
#include "src/common/common.h"

// QT
#include <QString>
#include <QStringList>


M_NAMESPACE_APP_BEGIN


  /*!
 * \brief Command line argument structure, can also parse QApplication args
 */
class MeltCommandLine
{
public:

  enum Mode
  {
    kMERGE_MODE,
    kDIFF_MODE,
    kTEST_MODE,
    kERROR
  };

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
   */
  static MeltCommandLine parse(const QStringList& args_);

  /*!
   * \brief Return base
   */
  const QString& base() const { return _basePath; }
  /*!
   * \brief Return local
   */
  const QString& local() const { return _localPath; }
  /*!
   * \brief Return remote
   */
  const QString& remote() const { return _remotePath; }
  /*!
   * \brief Return merge
   */
  const QString& merge() const { return _mergePath; }
  /*!
   * \brief Return mode
   */
  const Mode& mode() const { return _mode; }

  ~MeltCommandLine() {}

private:
  /*!
   * \brief Private default constructor
   * \param parent
   */
  MeltCommandLine() {}

  /*!
   * \brief Path to base file
   */
  QString _basePath;
  /*!
   * \brief Path to local file
   */
  QString _localPath;
  /*!
   * \brief Path to remote file
   */
  QString _remotePath;
  /*!
   * \brief Path to merge file
   */
  QString _mergePath;
  /*!
   * \brief Mode
   */
  Mode _mode;
};


M_NAMESPACE_APP_END
