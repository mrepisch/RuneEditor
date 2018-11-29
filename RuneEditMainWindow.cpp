#include "RuneEditMainWindow.h"
#include "ui_RuneEditMainWindow.h"
#include "MappingFactory.h"
#include <QDebug>
#include <QFileDialog>

const QString S_STYLE = QStringLiteral("font-size:30px;");

RuneEditMainWindow::RuneEditMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RuneEditMainWindow)
{
    ui->setupUi(this);
    m_mapping.reset(MappingFactory().generateMapping("elder"));
    m_mapping->writeToIni(QStringLiteral("config.ini"));
    ui->m_editText->installEventFilter(this);
    connect(ui->m_showLatin, &QCheckBox::toggled,this,&RuneEditMainWindow::toogleCheckbox);
    connect(ui->comboBox,SIGNAL(currentIndexChanged(int)), this, SLOT(mappingCbChanged(int)));
    connect( ui->actionOpen, &QAction::triggered, this, &RuneEditMainWindow::openMenuSlot);
    connect( ui->actionSaveAs, &QAction::triggered, this, &RuneEditMainWindow::saveAsSlot);
    connect( ui->actionSave, &QAction::triggered, this, &RuneEditMainWindow::saveSlot);
    connect( ui->actionExit, &QAction::triggered, this, &RuneEditMainWindow::exitSlot);

    ui->m_editText->setStyleSheet(S_STYLE );
    swapToRunes();



}

RuneEditMainWindow::~RuneEditMainWindow()
{
    delete ui;
}

bool RuneEditMainWindow::eventFilter(QObject *target, QEvent *event)
{
    if( !ui->m_showLatin->isChecked())
    {
        if( event->type() == QEvent::KeyPress)
        {
            QKeyEvent* keyevent = (QKeyEvent*)(event);
            if( keyevent != nullptr)
            {
                m_needsSaving = true;
                QString charachter = keyevent->text();
                QString rune = m_mapping->getValue(charachter.toLower());
                if( rune != QStringLiteral(" "))
                {
                    QString updatedText = ui->m_editText->toPlainText().append(rune);
                    int lastChar = updatedText.size();
                    ui->m_editText->setText(updatedText);
                    QTextCursor cursor = ui->m_editText->textCursor();
                    cursor.setPosition(lastChar);
                    ui->m_editText->setTextCursor(cursor);

                    return true;
                }


            }

        }

    }
    return false;
}

void RuneEditMainWindow::toogleCheckbox(bool t_toggled)
{
    if( t_toggled)
    {
        swapToLatin();
    }
    else
    {
        swapToRunes();
    }
}

void RuneEditMainWindow::mappingCbChanged(int t_index)
{
    MappingFactory fac;
    if( t_index == 0)
    {
        swapToLatin();
        m_mapping.reset(fac.generateMapping("elder"));

        swapToRunes();
        ui->m_showLatin->setChecked(false);
    }
    else if( t_index == 1)
    {
        swapToLatin();
        m_mapping.reset(fac.generateMapping("younger"));
        swapToRunes();
        ui->m_showLatin->setChecked(false);
    }
}

void RuneEditMainWindow::openMenuSlot()
{
    m_fileName = QFileDialog::getOpenFileName(this,
            tr("Open"), "",
            tr("Rune File (*.runes);;All Files (*)"));
    QFile file(m_fileName);
    if( file.exists() )
    {
        file.open(QIODevice::ReadOnly);
        QByteArray content = file.readAll();
        file.close();
        ui->m_editText->setText(QString(content));
    }
}

void RuneEditMainWindow::saveAsSlot()
{
   m_fileName = QFileDialog::getSaveFileName(this,
            tr("Save as..."), "",
            tr("Rune File (*.runes);;All Files (*)"));
   if( !m_fileName.contains(".runes"))
   {
       m_fileName += ".runes";
   }
   QFile file(m_fileName);
   file.open(QIODevice::WriteOnly);
   QTextStream streamFileOut(&file);
   streamFileOut.setCodec("UTF-8");
   streamFileOut << ui->m_editText->toPlainText();
   streamFileOut.flush();
   file.close();

}

void RuneEditMainWindow::saveSlot()
{
    QFile file(m_fileName);
    file.open(QIODevice::WriteOnly);
    QTextStream streamFileOut(&file);
    streamFileOut.setCodec("UTF-8");
    streamFileOut << ui->m_editText->toPlainText();
    streamFileOut.flush();
    file.close();

}

void RuneEditMainWindow::exitSlot()
{
    QApplication::exit();
}

void RuneEditMainWindow::swapToRunes()
{
    for( QObject* child : ui->centralWidget->children())
    {
        if( m_keys.contains(child->objectName()))
        {
            QPushButton* btn = (QPushButton*)(child);
            if( btn )
            {
                btn->setText( m_mapping->getValue(child->objectName()));
            }
        }
    }
    QString text = ui->m_editText->toPlainText();
    if( !text.isEmpty())
    {
        text = m_mapping->translateTextToValues(text);
        ui->m_editText->setText(text);
    }
}

void RuneEditMainWindow::swapToLatin()
{
    for( QObject* child : ui->centralWidget->children())
    {
        if( m_keys.contains(child->objectName()))
        {
            QPushButton* btn = (QPushButton*)(child);
            if( btn )
            {
                btn->setText( btn->objectName());
            }
        }
    }
    QString text = ui->m_editText->toPlainText();
    if( !text.isEmpty())
    {
        text = m_mapping->translateTextToKeys(text);
        ui->m_editText->setText(text);
    }
}
