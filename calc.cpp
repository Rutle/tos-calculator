#include "calc.hh"
#include "ui_calc.h"
#include "playableclasses.hh"
#include <iostream>


Calc::Calc(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Calc)
{
    ui->setupUi(this);

    // Choose a class from the ComboBox:
    connect(ui->chooseClassBox, SIGNAL(currentTextChanged(QString)),
            this, SLOT(on_chooseClassBox_currentTextChanged(QString)));
    // Spinboxes:
    connect(ui->sTRSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_sTRSpinBox_valueChanged(int)));
    connect(ui->cONSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_cONSpinBox_valueChanged(int)));
    connect(ui->iNTSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_iNTSpinBox_valueChanged(int)));
    connect(ui->sPRSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_sPRSpinBox_valueChanged(int)));
    connect(ui->dEXSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_dEXSpinBox_valueChanged(int)));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this,
            SLOT(on_resetButton_clicked()));
    connect(ui->rankSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_rankSpinBox_valueChanged(int)));

    chosen_class.add_class_stats(swordsman_stats, swordsman_mods, 1,
                                 "Swordsman", 1);
    ui->sTRSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->cONSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->iNTSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sPRSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dEXSpinBox->setMinimum(chosen_class.return_stat("DEX"));

    current_class_ = "Swordsman";
    update_stats();

}

Calc::~Calc() {
    delete ui;

}

void Calc::on_chooseClassBox_currentTextChanged(const QString &text) {

    std::string sText{text.toStdString()};
    current_class_ = sText;

    if ( sText == "Swordsman" ) {
        chosen_class.add_class_stats(swordsman_stats, swordsman_mods, 1, sText, 1);

    } else if ( sText == "Wizard") {
        chosen_class.add_class_stats(wizard_stats, wizard_mods, 1, sText, 1);

    } else if ( sText == "Archer") {
        chosen_class.add_class_stats(archer_stats, archer_mods, 1, sText, 1);

    } else if ( sText == "Cleric") {
        chosen_class.add_class_stats(cleric_stats, cleric_mods, 1, sText, 1);
    }

    ui->sTRSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->cONSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->iNTSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sPRSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dEXSpinBox->setMinimum(chosen_class.return_stat("DEX"));

    update_stats();

}
void Calc::update_stats() {

    ui->sTRSpinBox->setValue(chosen_class.return_stat("STR"));
    ui->cONSpinBox->setValue(chosen_class.return_stat("CON"));
    ui->iNTSpinBox->setValue(chosen_class.return_stat("INT"));
    ui->sPRSpinBox->setValue(chosen_class.return_stat("SPR"));
    ui->dEXSpinBox->setValue(chosen_class.return_stat("DEX"));

    std::string level{std::to_string(chosen_class.return_level())};
    ui->LevelOutput->setText(QString::fromStdString(level));

    ui->hPOutput->setNum(chosen_class.return_stat("HP"));
    ui->sPOutput->setNum(chosen_class.return_stat("SP"));
    ui->hPROutput->setNum(chosen_class.return_stat("HPR"));
    ui->sPROutput->setNum(chosen_class.return_stat("SPRE"));
    ui->physAttackOutput->setNum(chosen_class.return_stat("PAttack"));
    ui->secPhysAttackOutput->setNum(chosen_class.return_stat("SPAttack"));
    ui->mAttackOutput->setNum(chosen_class.return_stat("MAttack"));
    // ui->aoeAttackROutput->setNum(chosen_class.return_stat("AOEAR"));
    ui->accOutput->setNum(chosen_class.return_stat("Acc"));
    // ui->magicAOutput->setNum(chosen_class.return_stat("MAmp"));
    ui->blockPenOutput->setNum(chosen_class.return_stat("BlockPen"));
    ui->critAttackOutput->setNum(chosen_class.return_stat("CritAttack"));
    ui->critRateOutput->setNum(chosen_class.return_stat("CritRate"));
    ui->physDefOutput->setNum(chosen_class.return_stat("PhysDef"));
    ui->magicDefOutput->setNum(chosen_class.return_stat("MagDef"));
    // ui->aoeDefRatioOutput->setNum(chosen_class.return_stat("AOEDefR"));
    ui->evasionOutput->setNum(chosen_class.return_stat("Evasion"));
    // ui->blockOutput->setNum(chosen_class.return_stat("Block"));
    // ui->critResOutput->setNum(chosen_class.return_stat("CritRes"));
    // ui->staOutput->setNum(chosen_class.return_stat("STA"));
    ui->wlOutput->setNum(chosen_class.return_stat("WL"));
}

void Calc::on_sTRSpinBox_valueChanged(int value) {
    chosen_class.set_stat("STR", value);
    update_stats();

}
void Calc::on_cONSpinBox_valueChanged(int value) {
    chosen_class.set_stat("CON", value);
    update_stats();

}
void Calc::on_iNTSpinBox_valueChanged(int value) {
    chosen_class.set_stat("INT", value);
    update_stats();

}
void Calc::on_sPRSpinBox_valueChanged(int value) {
    chosen_class.set_stat("SPR", value);
    update_stats();

}
void Calc::on_dEXSpinBox_valueChanged(int value) {
    chosen_class.set_stat("DEX", value);
    update_stats();

}
void Calc::on_resetButton_clicked() {

    if ( current_class_ == "Swordsman" ) {
        chosen_class.add_class_stats(swordsman_stats, swordsman_mods, 1,
                                     current_class_, 1);

    } else if ( current_class_ == "Wizard") {
        chosen_class.add_class_stats(wizard_stats, wizard_mods, 1,
                                     current_class_, 1);

    } else if ( current_class_ == "Archer") {
        chosen_class.add_class_stats(archer_stats, archer_mods, 1,
                                     current_class_, 1);

    } else if ( current_class_ == "Cleric") {
        chosen_class.add_class_stats(cleric_stats, cleric_mods, 1,
                                     current_class_, 1);
    }
    ui->sTRSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->cONSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->iNTSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sPRSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dEXSpinBox->setMinimum(chosen_class.return_stat("DEX"));
    ui->rankSpinBox->setMinimum(1);

    update_stats();
}
void Calc::on_rankSpinBox_valueChanged(int value) {
    chosen_class.set_rank(value);
    update_stats();
}

void Calc::enable_spinboxes() {
    ui->sTRSpinBox->setEnabled(isEnabled());
    ui->cONSpinBox->setEnabled(isEnabled());
    ui->iNTSpinBox->setEnabled(isEnabled());
    ui->sPRSpinBox->setEnabled(isEnabled());
    ui->dEXSpinBox->setEnabled(isEnabled());
    ui->resetButton->setEnabled(isEnabled());
    ui->rankSpinBox->setEnabled(isEnabled());
}
void Calc::disable_spinboxes() {
    ui->sTRSpinBox->setEnabled(!isEnabled());
    ui->cONSpinBox->setEnabled(!isEnabled());
    ui->iNTSpinBox->setEnabled(!isEnabled());
    ui->sPRSpinBox->setEnabled(!isEnabled());
    ui->dEXSpinBox->setEnabled(!isEnabled());
    ui->resetButton->setEnabled(!isEnabled());
    ui->rankSpinBox->setEnabled(!isEnabled());
}
