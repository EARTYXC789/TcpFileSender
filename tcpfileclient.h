#ifndef TCPFILECLIENT_H
#define TCPFILECLIENT_H

#include <QDialog>

#include <QtNetwork>
#include <QtWidgets>

class TcpFileClient : public QDialog
{
    Q_OBJECT

public:
    explicit TcpFileClient(QWidget *parent = nullptr);
    ~TcpFileClient() override;

public slots:
    void start();
    void startTransfer();
    void updateClientProgress(qint64 numBytes);
    void openFile();

private:
    QProgressBar *clientProgressBar;
    QLabel *clientSatusLabel;
    QPushButton *startButton;
    QPushButton *quitButton;
    QPushButton *openButton;
    QDialogButtonBox *buttonBox;
    QTcpSocket tcpClient;

    qint64 totalBytes;
    qint64 bytesWritten;
    qint64 bytesToWrite;
    qint64 loadSize;
    QString fileName;
    QFile *loadFile;
    QByteArray outBlock;




};
#endif // TCPFILECLIENT_H
