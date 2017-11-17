#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QProcess>
#include <QMainWindow>
#include "common.h"
#include "qalgorithm.h"
#include "handletime.h"
#include "libxl.h"

#ifdef _WIN32
  #include <windows.h>
#endif

using namespace libxl;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void start();
    void main_window_init();
    void write_execl_head(unsigned int sheet_num);
    void set_sheet();
    void close();

private slots:
    void on_pushButton_write_clicked();
    void on_action_open_triggered();
    void on_action_create_triggered();
    void on_pushButton_reset_clicked();

    void on_pushButton_insert_ok_clicked();

    void on_pushButton_select_ok_clicked();

public slots:
    void recvMsg(QString msg);

signals:
    void sendMsg(QString msg);

private:
    Ui::MainWindow *ui;

    QString m_product_type;
    QString m_product_size;
    QString m_product_color;
    QString m_baterry_type;
    QString m_water_proof;
    QString m_execl_dir;
    QString m_execlfile_name;
    QString m_log_str;
    QString m_execl_tail;
    QString m_err_info;
    QString m_ui_time;
    QString m_year_str;
    QString m_week_str;
    QString m_day_str;

    unsigned int m_start_id;
    unsigned int m_ispd_num;

    qint32 m_year;
    qint32 m_week;
    qint32 m_day;

    QStringList m_protype_array;
    QStringList m_prosize_array;
    QStringList m_procolor_array;
    QStringList m_battype_array;
    QStringList m_watproof_array;
    QStringList m_execltail_array;
    QStringList m_uitime_array;

    char *m_file_name;
    unsigned int m_sheet_num;

    HandleTime* m_time;
    QAlgorithm* m_gorithm;
    common*     m_com;
    Book* m_book;
    Sheet* m_sheet;

    float upload_rate;
    float upload_process;
};

#endif // MAINWINDOW_H
