#pragma once


// QT
#include <QApplication>
#include <QSharedPointer>


namespace app
{

class MeltCommandLine;
/*!
 * \brief The MeltApplication class
 */
class MeltApplication : public QApplication
{
public:
    explicit MeltApplication(int argc, char* argv[]);
    ~MeltApplication();

private:
  /*!
   * \brief Command line arguments
   */
  QSharedPointer<const MeltCommandLine> _arguments;
};


} // namespace app
