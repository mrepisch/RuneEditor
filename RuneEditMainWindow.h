#ifndef RUNEEDITMAINWINDOW_H
#define RUNEEDITMAINWINDOW_H

#include <QMainWindow>
#include <QStringList>
#include <QKeyEvent>
#include "Mapping.h"
#include <QScopedPointer>
namespace Ui {
class RuneEditMainWindow;
}

class RuneEditMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit RuneEditMainWindow(QWidget *parent = nullptr);
    ~RuneEditMainWindow();

    bool eventFilter(QObject *target, QEvent *event);

private slots:
    void toogleCheckbox(bool t_toggled);

    void mappingCbChanged( int t_index);

    void openMenuSlot();
    void saveAsSlot();
    void saveSlot();
    void exitSlot();

private:

    void swapToRunes();
    void swapToLatin();

    Ui::RuneEditMainWindow *ui;
    QScopedPointer<Mapping> m_mapping;
    QStringList m_keys =
    {
        "q","w","e","r","t","z","u","i","o","p",
        "a","s","d","f","g","h","i","j","k","l",
        "y","x","c","v","b","n","n","m"
    };
    bool m_needsSaving = false;
    const QString S_DEFAULT_FILENAME = "noname.rune";
    QString m_fileName = S_DEFAULT_FILENAME;
};

#endif // RUNEEDITMAINWINDOW_H
