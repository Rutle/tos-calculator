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
    connect(ui->strSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_strSpinBox_valueChanged(int)));
    connect(ui->conSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_conSpinBox_valueChanged(int)));
    connect(ui->intSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_intSpinBox_valueChanged(int)));
    connect(ui->sprSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_sprSpinBox_valueChanged(int)));
    connect(ui->dexSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_dexSpinBox_valueChanged(int)));
    connect(ui->resetButton, SIGNAL(clicked(bool)), this,
            SLOT(on_resetButton_clicked()));
    connect(ui->rankSpinBox, SIGNAL(valueChanged(int)), this,
            SLOT(on_rankSpinBox_valueChanged(int)));

    chosen_class.add_class_stats(swordsman_stats, swordsman_mods, 1,
                                 "Swordsman", 1);
    ui->strSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->conSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->intSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sprSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dexSpinBox->setMinimum(chosen_class.return_stat("DEX"));

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

    ui->strSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->conSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->intSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sprSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dexSpinBox->setMinimum(chosen_class.return_stat("DEX"));

    update_stats();

}
void Calc::update_stats() {

    ui->strSpinBox->setValue(chosen_class.return_stat("STR"));
    ui->conSpinBox->setValue(chosen_class.return_stat("CON"));
    ui->intSpinBox->setValue(chosen_class.return_stat("INT"));
    ui->sprSpinBox->setValue(chosen_class.return_stat("SPR"));
    ui->dexSpinBox->setValue(chosen_class.return_stat("DEX"));

    std::string level{std::to_string(chosen_class.return_level())};
    ui->LevelOutput->setText(QString::fromStdString(level));

    ui->hpOutput->setNum(chosen_class.return_stat("HP"));
    ui->spOutput->setNum(chosen_class.return_stat("SP"));
    ui->hprOutput->setNum(chosen_class.return_stat("HPR"));
    ui->sprOutput->setNum(chosen_class.return_stat("SPRE"));
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

void Calc::on_strSpinBox_valueChanged(int value) {
    chosen_class.set_stat("STR", value);
    update_stats();

}
void Calc::on_conSpinBox_valueChanged(int value) {
    chosen_class.set_stat("CON", value);
    update_stats();

}
void Calc::on_intSpinBox_valueChanged(int value) {
    chosen_class.set_stat("INT", value);
    update_stats();

}
void Calc::on_sprSpinBox_valueChanged(int value) {
    chosen_class.set_stat("SPR", value);
    update_stats();

}
void Calc::on_dexSpinBox_valueChanged(int value) {
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
    ui->strSpinBox->setMinimum(chosen_class.return_stat("STR"));
    ui->conSpinBox->setMinimum(chosen_class.return_stat("CON"));
    ui->intSpinBox->setMinimum(chosen_class.return_stat("INT"));
    ui->sprSpinBox->setMinimum(chosen_class.return_stat("SPR"));
    ui->dexSpinBox->setMinimum(chosen_class.return_stat("DEX"));
    ui->rankSpinBox->setMinimum(1);

    update_stats();
}
void Calc::on_rankSpinBox_valueChanged(int value) {
    chosen_class.set_rank(value);
    update_stats();
}

void Calc::enable_spinboxes() {
    ui->strSpinBox->setEnabled(isEnabled());
    ui->conSpinBox->setEnabled(isEnabled());
    ui->intSpinBox->setEnabled(isEnabled());
    ui->sprSpinBox->setEnabled(isEnabled());
    ui->dexSpinBox->setEnabled(isEnabled());
    ui->resetButton->setEnabled(isEnabled());
    ui->rankSpinBox->setEnabled(isEnabled());
}
void Calc::disable_spinboxes() {
    ui->strSpinBox->setEnabled(!isEnabled());
    ui->conSpinBox->setEnabled(!isEnabled());
    ui->intSpinBox->setEnabled(!isEnabled());
    ui->sprSpinBox->setEnabled(!isEnabled());
    ui->dexSpinBox->setEnabled(!isEnabled());
    ui->resetButton->setEnabled(!isEnabled());
    ui->rankSpinBox->setEnabled(!isEnabled());
}
