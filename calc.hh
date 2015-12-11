#ifndef CALC_HH
#define CALC_HH

#include "playableclasses.hh"
#include <QWidget>
#include <map>
#include <string>

namespace Ui {
class Calc;
}

class Calc : public QWidget {
    Q_OBJECT

public:
    explicit Calc(QWidget *parent = 0);
    ~Calc();
public slots:
    void on_chooseClassBox_currentTextChanged(const QString& text);
    void on_sTRSpinBox_valueChanged(int value);
    void on_cONSpinBox_valueChanged(int value);
    void on_iNTSpinBox_valueChanged(int value);
    void on_sPRSpinBox_valueChanged(int value);
    void on_dEXSpinBox_valueChanged(int value);
    void on_resetButton_clicked();
    void on_rankSpinBox_valueChanged(int value);


private:
    void disable_spinboxes();
    void enable_spinboxes();
    void update_stats();
    Ui::Calc *ui;
    PlayableClasses chosen_class;
    std::string current_class_;
    // Main stats: STR, CON, INT, SPR, DEX
    std::map<std::string, int> swordsman_stats{
        {"STR", 7}, {"CON", 8}, {"INT", 2}, {"SPR", 3}, {"DEX", 5}
    };
    std::map<std::string, int> wizard_stats{
        {"STR", 3}, {"CON", 3}, {"INT", 8}, {"SPR", 7}, {"DEX", 4}
    };
    std::map<std::string, int> archer_stats{
        {"STR", 6}, {"CON", 3}, {"INT", 3}, {"SPR", 4}, {"DEX", 8}
    };
    std::map<std::string, int> cleric_stats{
        {"STR", 5}, {"CON", 6}, {"INT", 4}, {"SPR", 4}, {"DEX", 3}
    };

    // HP and SP modifiers:
    std::map<std::string, double> swordsman_mods{
        {"HPM", 3.3}, {"SPM", 0.8}
    };
    std::map<std::string, double> wizard_mods{
        {"HPM", 1.1}, {"SPM", 1.2}
    };
    std::map<std::string, double> archer_mods{
        {"HPM", 1.4}, {"SPM", 0.9}
    };
    std::map<std::string, double> cleric_mods{
        {"HPM", 1.5}, {"SPM", 1.2}
    };

};

#endif // CALC_HH
