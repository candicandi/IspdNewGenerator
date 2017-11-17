#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSettings>
#include <QDebug>
#include <QStringList>
#include <QScopedPointer>
#include <QFileDialog>
#include <QDateTime>
#include <QTextCursor>
#include <QMessageBox>
#include <QDir>

#define MESSAGE_RED "<font size = 200 color = red ><strong>"
#define MESSAGE_GREEN "<font size = 200 color = blue ><strong>"
#define MESSAGE_END "</strong></font>"

char g_array[512];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDir dir;
    QString program_path = dir.currentPath();
    QString path = program_path + "/config.ini";
    //"C:/Users/guoshijiang/Desktop/libxl-3.8.1.0/examples/c++/IspdGenerator/config.ini"
    QSettings settings(path, QSettings::IniFormat);
    this->m_product_type = settings.value("product_type").toString();
    this->m_product_size = settings.value("product_size").toString();
    this->m_product_color = settings.value("product_color").toString();
    this->m_baterry_type = settings.value("baterry_type").toString();
    this->m_water_proof = settings.value("water_proof").toString();
    this->m_execl_dir = settings.value("execl_dir").toString();
    this->m_execl_tail = settings.value("execl_tail").toString();
    if(this->m_product_type != NULL)
    {
        this->m_protype_array = this->m_product_type.split("|");
    }
    if(this->m_product_size != NULL)
    {
        this->m_prosize_array = this->m_product_size.split("|");
    }
    if(this->m_product_color != NULL)
    {
        this->m_procolor_array = this->m_product_color.split("|");
    }
    if(this->m_baterry_type != NULL)
    {
        this->m_battype_array = this->m_baterry_type.split("|");
    }
    if(this->m_water_proof != NULL)
    {
        this->m_watproof_array = this->m_water_proof.split("|");
    }
    if(this->m_execl_tail != NULL)
    {
        this->m_execltail_array = this->m_execl_tail.split("|");
    }
    ui->setupUi(this);
    this->ui->uploadProgressBar->setMinimum(0);
    this->ui->uploadProgressBar->setMaximum(100);
    this->ui->uploadProgressBar->setValue(0);
}

void MainWindow::main_window_init()
{
    for(qint32 i = 0; i < this->m_protype_array.size(); i++)
    {
        ui->comboBox_type->addItem(this->m_protype_array[i]);
    }
    for(qint32 i = 0; i < this->m_prosize_array.size(); i++)
    {
        ui->comboBox_size->addItem(this->m_prosize_array[i]);
    }
    for(qint32 i = 0; i < this->m_procolor_array.size(); i++)
    {
        ui->comboBox_color->addItem(this->m_procolor_array[i]);
    }
    for(qint32 i = 0; i < this->m_battype_array.size(); i++)
    {
        ui->comboBox_bat->addItem(this->m_battype_array[i]);
    }
    for(qint32 i = 0; i < this->m_watproof_array.size(); i++)
    {
        ui->comboBox_water->addItem(this->m_watproof_array[i]);
    }
    this->ui->dateEdit->setDateTime(QDateTime::currentDateTime());
    this->m_book = xlCreateBook();
    if(!this->m_book) return ;

    this->m_time = new HandleTime();
    this->m_gorithm = new QAlgorithm();
    this->m_com = new common();

    this->ui->pushButton_insert_ok->setEnabled(false);
    this->ui->pushButton_reset->setEnabled(false);
    this->ui->pushButton_select_ok->setEnabled(false);
    this->ui->pushButton_write->setEnabled(false);
}

MainWindow::~MainWindow()
{
    close();
    delete ui;
    if(m_time != NULL)
    {
        delete m_time;
        m_time = NULL;
    }

    if(m_gorithm != NULL)
    {
        delete m_gorithm;
        m_gorithm = NULL;
    }
    if(m_com != NULL)
    {
        delete m_com;
        m_com = NULL;
    }
}

void MainWindow::start()
{
    this->setWindowTitle("超级版标签码自动生成软件");
    this->setWindowIcon(QIcon("app_icon_32.ico"));
    this->setWindowFlags(windowFlags()|Qt::WindowMinimizeButtonHint|Qt::WindowStaysOnTopHint);
    this->showNormal();
    main_window_init();
    connect(this, SIGNAL(sendMsg(QString)), this, SLOT(recvMsg(QString)));
}

void MainWindow::on_action_create_triggered()
{
    QString fpath = QCoreApplication::applicationDirPath() + "/path";
    QFileDialog dialog(this);
    dialog.setWindowTitle(tr("新建文件"));
    dialog.setAcceptMode(QFileDialog::AcceptSave);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setViewMode(QFileDialog::Detail);
    dialog.setDirectory(fpath);
    dialog.setNameFilter("execl file(*.xls *.xlsx)");
    if(QDialog::Accepted == dialog.exec())
    {
        QString sentence_log = tr("创建文档成功:");
        QString new_file_name = dialog.selectedFiles()[0];
        if(!this->m_book)
        {
           this->m_book = xlCreateBook();
        }
        this->m_sheet = this->m_book->addSheet("Sheet1");
        if(!this->m_sheet)
        {
            return ;
        }
        QByteArray b_file_name = new_file_name.toLocal8Bit();
        this->m_file_name = b_file_name.data();
        strcpy(g_array, this->m_file_name);
        this->m_book->save(m_file_name);
        this->m_log_str = sentence_log + new_file_name;
        ui->textEdit_optlog->append(this->m_log_str);
        this->ui->pushButton_insert_ok->setEnabled(true);
        this->ui->pushButton_select_ok->setEnabled(true);
    }
    this->ui->comboBox_select_sheet->addItem("Sheet1");
}

void MainWindow::on_action_open_triggered()
{
    QString xls_file_name = QFileDialog::getOpenFileName(this,QString(),QString(),"excel(*.xls *.xlsx)");
    if(xls_file_name.isEmpty())
    {
       return ;
    }
    QByteArray b_execlfile_name = xls_file_name.toLocal8Bit();
    this->m_file_name = b_execlfile_name.data();
    strcpy(g_array, this->m_file_name);
    if(!this->m_book)
    {
        this->m_book = xlCreateBook();
    }
    if(!this->m_book->load(this->m_file_name))
    {
        return ;
    }
    int ret_num =  this->m_book->sheetCount();
    QString sentence_log = tr("打开文件成功:");
    this->m_log_str = sentence_log + this->m_execlfile_name;
    ui->textEdit_optlog->append(m_log_str);
    for(unsigned int i = 1; i <= ret_num; i++)
    {
        QString sheet_num = QString::number(i);
        this->ui->comboBox_select_sheet->addItem("Sheet" + sheet_num);
    }
    this->ui->pushButton_insert_ok->setEnabled(false);
    this->ui->pushButton_select_ok->setEnabled(true);
}

void MainWindow::on_pushButton_write_clicked()
{
    static int A_I = 1;
    QString       ispd_year;
    QString       ispd_week;
    QString       ispd_day;
    char          psztemp[64] = {0};
    QString       encrypt_str;
    if(this->ui->lineEdit_startid->text() == NULL || this->ui->lineEdit_need_num->text() == NULL)
    {
        this->m_err_info = tr("起始ID或者录入的需求个数为空,请您必须输入!");
        QString err_info = MESSAGE_RED + m_err_info + MESSAGE_END;
        QMessageBox::warning(this, tr("警告"), err_info);
        qCritical() << m_err_info;
        this->ui->textEdit_optlog->append(m_err_info);
        return ;
    }
    this->m_ui_time =  ui->dateEdit->text();
    if(this->m_ui_time != NULL)
    {
      this->m_uitime_array  = this->m_ui_time.split("/");
    }
    for(qint32 i = 0; i < this->m_uitime_array.size(); i++)
    {
        this->m_year_str  = this->m_uitime_array[0];
        this->m_week_str = this->m_uitime_array[1];
        this->m_day_str   = this->m_uitime_array[2];
    }
    this->m_year = this->m_year_str.toInt();
    this->m_week = this->m_week_str.toInt();
    this->m_day = this->m_day_str.toInt();

    this->upload_process = 0;
    this->ui->uploadProgressBar->setValue(this->upload_process);

    this->m_start_id = ui->lineEdit_startid->text().toInt();
    this->m_ispd_num = ui->lineEdit_need_num->text().toInt();
    QDate date(QDate::currentDate());
    int this_year = date.year();
    qint16 week = date.weekNumber(&(this_year));
    ispd_year = this->m_time->Handle_year(this->m_year);
    ispd_week = this->m_time->week_of_year(this->m_year, this->m_week, this->m_day);
    ispd_day =  this->m_time->day_of_week(this->m_year, this->m_week, this->m_day);

    this->upload_rate = 100.0 / float(this->m_ispd_num);

    QString ispd_color = this->m_com->handle_color(ui->comboBox_color->currentText().trimmed());
    QString ispd_size = this->m_com->handle_size(ui->comboBox_size->currentText().trimmed());

    if(!this->m_book)
    {
        this->m_book = xlCreateBook();
    }

    this->m_sheet = m_book->getSheet(this->m_sheet_num);
    if(!this->m_sheet)
    {
        return ;
    }
    QString pro_type = this->ui->comboBox_type->currentText();
    QByteArray b_pro_type = pro_type.toLatin1();
    char* p_pro_type_str = b_pro_type.data();

    QString pro_color = this->ui->comboBox_color->currentText();
    QByteArray b_pro_color = pro_color.toLocal8Bit();
    char* p_pro_color_str = b_pro_color.data();

    QString pro_bat = this->ui->comboBox_bat->currentText();
    QByteArray b_pro_bat = pro_bat.toLocal8Bit();
    char* p_pro_bat_str = b_pro_bat.data();

    QString pro_water = this->ui->comboBox_water->currentText();
    QByteArray b_pro_water = pro_water.toLatin1();
    char* p_pro_water_str = b_pro_water.data();

    QString pro_v = this->ui->lineEdit_v->text();
    QByteArray b_pro_v = pro_v.toLocal8Bit();
    char* p_pro_v_str = b_pro_v.data();

    QString pro_i = this->ui->lineEdit_i->text();
    QByteArray b_pro_i = pro_i.toLocal8Bit();
    char* p_pro_i_str = b_pro_i.data();

    QString pro_cap = this->ui->lineEdit_cap->text();
    QByteArray b_pro_cap = pro_cap.toLocal8Bit();
    char* p_pro_cap_str = b_pro_cap.data();

    for(unsigned int i = this->m_start_id; i < (this->m_start_id + this->m_ispd_num); i++)
    {
        QString sentence_log = tr("数据写入Eexecl文件成功:");
        QDateTime time = QDateTime::currentDateTime();
        QString time_str = time.toString("yyyy-MM-dd hh:mm:ss");
        QByteArray b_time_arr = time_str.toLatin1();
        char *p_time_str = b_time_arr.data();

        int ispd_int_id = i;
        QString ispd_str_id = QString::number(100) + QString::number(ispd_int_id);
        QByteArray b_str_id_arr = ispd_str_id.toLatin1();
        char *p_str_id_str = b_str_id_arr.data();

        snprintf(psztemp, 64, "%u", ispd_int_id);
        assert(0 != strlen(psztemp));
        unsigned int base = pow(10, strlen(psztemp)) *  100;
        encrypt_str = this->m_gorithm->encrypt_ispd_id(ispd_int_id + base);

        QString ser_number = ispd_year + QString::number(week) + ispd_day + ui->comboBox_type->currentText() +
                ispd_color + ispd_size + encrypt_str;

        QByteArray b_ser_number_arr = ser_number.toLatin1();
        char *p_ser_number_str = b_ser_number_arr.data();

        QString domain_str = tr("http://m.cjqc.com/sg/");
        QString ewm_str = domain_str + encrypt_str;
        QByteArray b_ewm_arr = ewm_str.toLatin1();
        char *p_ewm_str = b_ewm_arr.data();

        QByteArray b_encrypt_arr = encrypt_str.toLatin1();
        char *p_encrypt_str = b_encrypt_arr.data();

        this->m_sheet->writeStr(++A_I, 0, p_str_id_str);
        this->m_sheet->writeStr(A_I, 1, p_encrypt_str);
        this->m_sheet->writeStr(A_I, 2, p_ewm_str);
        this->m_sheet->writeStr(A_I, 3, p_pro_type_str);
        this->m_sheet->writeStr(A_I, 4, p_pro_color_str);
        this->m_sheet->writeStr(A_I, 5, p_pro_bat_str);
        this->m_sheet->writeStr(A_I, 6, p_pro_water_str);
        this->m_sheet->writeStr(A_I, 7, p_pro_v_str);
        this->m_sheet->writeStr(A_I, 8, p_pro_i_str);
        this->m_sheet->writeStr(A_I, 9, p_pro_cap_str);
        this->m_sheet->writeStr(A_I, 10, p_ser_number_str);
        this->m_sheet->writeStr(A_I, 11, p_time_str);
        this->upload_process += this->upload_rate;
        this->ui->uploadProgressBar->setValue(int(this->upload_process));
        QString log = sentence_log + ispd_int_id + ui->comboBox_type->currentText()
                + ui->comboBox_color->currentText() + ui->comboBox_bat->currentText() +
                ui->comboBox_water->currentText() + ui->lineEdit_v->text() + ui->lineEdit_i->text()
                + ui->lineEdit_cap->text() + QString::number(i) + time_str;
        emit sendMsg(log);
    }
    this->ui->uploadProgressBar->setValue(100);
    this->m_book->save(g_array);
    ui->label_status_result->setText(tr("写入Execl文件成功"));
    this->ui->pushButton_reset->setEnabled(true);
}

void MainWindow::recvMsg(QString msg)
{
    this->m_log_str = msg;
    ui->textEdit_optlog->append(this->m_log_str);
}

void MainWindow::on_pushButton_reset_clicked()
{
    ui->lineEdit_startid->clear();
    ui->lineEdit_need_num->clear();
    this->ui->uploadProgressBar->setValue(0);
    ui->lineEdit_i->clear();
    ui->lineEdit_v->clear();
    ui->lineEdit_cap->clear();
    ui->textEdit_optlog->clear();
    ui->label_status_result->setText(tr("重置成功"));
}

void MainWindow::on_pushButton_insert_ok_clicked()
{
    static int i = 0;
    QString sentence_log = tr("插入工作sheet成功:");
    QString sh_name = this->ui->comboBox_sheet->currentText();
    QString sh_num = this->ui->comboBox_sheet_num->currentText();
    QString sheet_name = sh_name + sh_num;
    QByteArray b_sheet_name = sheet_name.toLocal8Bit();
    char *p_b_sheet_name = b_sheet_name.data();
    this->m_sheet = this->m_book->insertSheet(++i, p_b_sheet_name);
    this->m_book->save(g_array);
    this->ui->comboBox_select_sheet->addItem(sheet_name);
    QString c_str_log = QString(QLatin1String(g_array));
    this->m_log_str = sentence_log + c_str_log + tr("Sheet的名字为:") + sheet_name;
    ui->textEdit_optlog->append(m_log_str);
}

void MainWindow::on_pushButton_select_ok_clicked()
{
    this->m_sheet_num = this->ui->comboBox_select_sheet->currentIndex();
    QString sentence_log = tr("选择工作sheet成功:");
    this->m_log_str = sentence_log + QString::number(this->m_sheet_num + 1);
    ui->textEdit_optlog->append(m_log_str);
    write_execl_head(this->m_sheet_num);
    this->ui->pushButton_write->setEnabled(true);
}

void MainWindow::write_execl_head(unsigned int sheet_num)
{
    if(!this->m_book)
    {
        this->m_book = xlCreateBook();
    }

    this->m_sheet = m_book->getSheet(sheet_num);
    if(!this->m_sheet)
    {
        return ;
    }
    qDebug() << "this->m_sheet = " <<  this->m_sheet;
    QString ispd_id_str = tr("CJBYSID");
    QByteArray ispd_id_arr = ispd_id_str.toLocal8Bit();
    char *ispd_id_c = ispd_id_arr.data();
    this->m_sheet->writeStr(1, 0, ispd_id_c);

    QString ispd_erm_str = tr("CJBJMID");
    QByteArray ispd_ewm_arr = ispd_erm_str.toLocal8Bit();
    char *ispd_erm_c = ispd_ewm_arr.data();
    this->m_sheet->writeStr(1, 1, ispd_erm_c);

    QString ispd_enid_str = tr("EWMID");
    QByteArray ispd_enid_arr = ispd_enid_str.toLocal8Bit();
    char *ispd_enid_c = ispd_enid_arr.data();
    this->m_sheet->writeStr(1, 2, ispd_enid_c);

    QString ispd_type_str = tr("CPXH");
    QByteArray ispd_type_arr = ispd_type_str.toLocal8Bit();
    char *ispd_type_c = ispd_type_arr.data();
    this->m_sheet->writeStr(1, 3, ispd_type_c);

    QString ispd_color_str = tr("CPYS");
    QByteArray ispd_color_arr = ispd_color_str.toLocal8Bit();
    char *ispd_color_c = ispd_color_arr.data();
    this->m_sheet->writeStr(1, 4, ispd_color_c);

    QString ispd_battype_str = tr("DCLX");
    QByteArray ispd_battype_arr = ispd_battype_str.toLocal8Bit();
    char *ispd_battype_c = ispd_battype_arr.data();
    this->m_sheet->writeStr(1, 5, ispd_battype_c);

    QString ispd_water_str = tr("FSDJ");
    QByteArray ispd_water_arr = ispd_water_str.toLocal8Bit();
    char *ispd_water_c = ispd_water_arr.data();
    this->m_sheet->writeStr(1, 6, ispd_water_c);

    QString ispd_v_str = tr("SRDY");
    QByteArray ispd_v_arr = ispd_v_str.toLocal8Bit();
    char *ispd_v_c = ispd_v_arr.data();
    this->m_sheet->writeStr(1, 7, ispd_v_c);

    QString ispd_i_str = tr("SYDL");
    QByteArray ispd_i_arr = ispd_i_str.toLocal8Bit();
    char *ispd_i_c = ispd_i_arr.data();
    this->m_sheet->writeStr(1, 8, ispd_i_c);

    QString ispd_batcap_str = tr("DCRL");
    QByteArray ispd_batcap_arr = ispd_batcap_str.toLocal8Bit();
    char *ispd_batcap_c = ispd_batcap_arr.data();
    this->m_sheet->writeStr(1, 9, ispd_batcap_c);

    QString ispd_sernum_str = tr("XLH");
    QByteArray ispd_sernum_arr = ispd_sernum_str.toLocal8Bit();
    char *ispd_sernum_c = ispd_sernum_arr.data();
    this->m_sheet->writeStr(1, 10, ispd_sernum_c);

    QString ispd_datetime_str = tr("RQSJ");
    QByteArray ispd_datatime_arr = ispd_datetime_str.toLocal8Bit();
    char *ispd_datetime_c = ispd_datatime_arr.data();
    this->m_sheet->writeStr(1, 11, ispd_datetime_c);

    this->m_book->save(g_array);
    QString sentence_log = tr("设置execl的头部成功:设置项包括->超级版原始ID->超级版加密ID->二维码ID->产品型号"
                              "->产品颜色->电池类型->防水等级->输入电压->输入电流->电池容量->"
                              "序列号->日期时间");
    this->m_log_str  = sentence_log;
    ui->textEdit_optlog->append(m_log_str);
    ui->label_status_result->setText(tr("设置execl头成功"));
    ui->pushButton_write->setEnabled(true);
}

void MainWindow::set_sheet()
{
    return ;
}

void MainWindow::close()
{
    this->m_book->release();
    QString sentence_log = tr("关闭execl成功:");
    QString log_array = QString(QLatin1String(g_array));
    this->m_log_str = sentence_log + log_array;
    ui->textEdit_optlog->append(this->m_log_str);
}
