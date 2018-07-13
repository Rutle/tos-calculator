#include "playableclasses.hh"
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cmath>

const std::vector<std::string> sub_stat_categories{
    "HP", "SP", "HPR", "SPRE", "PAttack", "SPAttack", "MAttack", "AOEAR", "Acc",
    "MAmp", "BlockPen", "CritAttack", "CritRate", "PhysDef", "MagDef",
    "AOEDefR", "Evasion", "Block", "CritRes" ,"STA", "WL",};

PlayableClasses::PlayableClasses():
    mainstats_{{"STR", 0}, {"CON", 0}, {"INT", 0}, {"SPR", 0}, {"DEX", 0}},
    modifiers_{{"HPM", 0.0}, {"SPM", 0.0}, {"STR_Rank_Bonus", 0.0},
               {"INT_Rank_Bonus", 0.0}}, level_{1},
    sub_stats_{{"HP", 0}, {"SP", 0}, {"HPR", 0}, {"SPRE", 0}, {"PAttack", 0},
               {"SPAttack", 0}, {"MAttack", 0}, {"AOEAR", 0},
               {"Acc", 0}, {"MAmp", 0}, {"BlockPen", 0}, {"CritAttack", 0},
               {"CritRate", 0}, {"PhysDef", 0}, {"MagDef", 0}, {"AOEDefR", 0},
               {"Evasion", 0}, {"Block", 0}, {"CritRes", 0}, {"STA", 0},
               {"WL", 0}}, class_name_{"None"},
    total_invested_stats_{{"STR", 0}, {"CON", 0}, {"INT", 0}, {"SPR", 0},
               {"DEX", 0}}, rank_{1}
{
}

PlayableClasses::PlayableClasses(const std::map<std::string, int>& stats,
                                 const std::map<std::string, double>& mods,
                                 int level, std::string class_name, int rank):
    mainstats_{stats}, modifiers_{mods}, level_{level},
    class_name_{class_name}, rank_{rank}

{

}
PlayableClasses::PlayableClasses(const PlayableClasses& sijoitus) :
    mainstats_{sijoitus.mainstats_}, modifiers_{sijoitus.modifiers_},
    level_{sijoitus.level_}, sub_stats_{sijoitus.sub_stats_},
    class_name_{sijoitus.class_name_}, rank_{sijoitus.rank_}{
    calculate_sub_stats();

}

void PlayableClasses::add_class_stats(const std::map<std::string, int>& stats,
                         const std::map<std::string, double>& mods,
                         int level, std::string class_name, int rank) {
    mainstats_ = stats;
    modifiers_ = mods;
    level_ = level;
    class_name_ = class_name;
    rank_ = rank;
    calculate_sub_stats();

}
int PlayableClasses::return_stat(const std::string& stat_name) const {
    if ( mainstats_.find(stat_name) != mainstats_.end() ) {
        return mainstats_.at(stat_name);
    } else if ( sub_stats_.find(stat_name) != sub_stats_.end() ){
        return sub_stats_.at(stat_name);
    } else {
        return modifiers_.at(stat_name);
    }
}

int PlayableClasses::return_level() const {
    return level_;
}
void PlayableClasses::reset_stats() {
    mainstats_ = {{"STR", 0}, {"CON", 0}, {"INT", 0}, {"SPR", 0}, {"DEX", 0}};
    total_invested_stats_ = {{"STR", 0}, {"CON", 0}, {"INT", 0}, {"SPR", 0},
                             {"DEX", 0}};
    modifiers_ = {{"HPM", 0.0}, {"SPM", 0.0}, {"STR_Rank_Bonus", 0.0},
                  {"INT_Rank_Bonus", 0.0}};
    level_ = 1;
    sub_stats_ = {{"HP", 0}, {"SP", 0}, {"HPR", 0}, {"SPRE", 0}, {"PAttack", 0},
               {"SPAttack", 0}, {"MAttack", 0}, {"AOEAR", 0},
               {"Acc", 0}, {"MAmp", 0}, {"BlockPen", 0}, {"CritAttack", 0},
               {"CritRate", 0}, {"PhysDef", 0}, {"MagDef", 0}, {"AOEDefR", 0},
               {"Evasion", 0}, {"Block", 0}, {"CritRes", 0}, {"STA", 0},
               {"WL", 0}};
    class_name_ = "None";
    rank_ = 1;
    calculate_sub_stats();
}

void PlayableClasses::calculate_sub_stats() {

    for ( auto sub_stat_name: sub_stats_ ) {
        // double class_modifier{0.0};
        double new_calculated_stat{0};
        if ( sub_stat_name.first == "HP" ) {
            new_calculated_stat = modifiers_.at("HPM") * ((level_ - 1) * 17.0)
                    + (mainstats_.at("CON") * 85);
            // sub_stats_.at("HP") = int(new_calculated_stat + 0.5 );

        } else if ( sub_stat_name.first == "SP" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Cleric") {
                class_modifier = level_ * 1.675;

            }
            // std::cout << "SP [" << class_modifier << "]" << std::endl;
            new_calculated_stat =
                    modifiers_.at("SPM") * ((level_ - 1) * 6.7) +
                    (mainstats_.at("SPR") * 13) + class_modifier;
            // sub_stats_.at("SP") = int(new_calculated_stat + 0.5);

        } else if ( sub_stat_name.first == "HPR" ) {
            new_calculated_stat = level_ * 0.5 + mainstats_.at("CON");
            // sub_stats_.at("HPR") = int(new_calculated_stat + 0.5);

        } else if ( sub_stat_name.first == "SPRE" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Cleric" ) {
                class_modifier = level_ * 0.25;
            }
            new_calculated_stat = level_ * 0.5 + mainstats_.at("SPR") +
                    class_modifier;
            // sub_stats_.at("SPR") = int(new_calculated_stat + 0.5);

        } else if ( sub_stat_name.first == "PAttack" ) {
            new_calculated_stat = level_ + mainstats_.at("STR");
            // sub_stats_.at("PAttack") = int(new_calculated_stat + 0.5);
        } else if ( sub_stat_name.first == "SPAttack" ) {
            new_calculated_stat = level_ + mainstats_.at("STR");
        } else if ( sub_stat_name.first == "MAttack" ) {
            new_calculated_stat = level_ + mainstats_.at("INT");
        } else if ( sub_stat_name.first == "AOEAR" ) {
            // new_calculated_stat = level_ + mainstats_.at("STR");
        } else if ( sub_stat_name.first == "Acc" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Archer" ) {
                class_modifier = (level_ + 4) / 4;
            }
            new_calculated_stat = level_ + mainstats_.at("DEX") +
                    class_modifier;
        } else if ( sub_stat_name.first == "MAmp" ) {
            // new_calculated_stat = level_ + mainstats_.at("STR");
        } else if ( sub_stat_name.first == "BlockPen" ) {
            new_calculated_stat = level_ * 0.5 + mainstats_.at("SPR");
        } else if ( sub_stat_name.first == "CritAttack" ) {
            new_calculated_stat = mainstats_.at("STR");
        } else if ( sub_stat_name.first == "CritRate" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Archer" ) {
                class_modifier = (level_ / 5);
            }
            new_calculated_stat = mainstats_.at("DEX") + class_modifier;
        } else if ( sub_stat_name.first == "PhysDef" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Swordsman" ) {
                class_modifier = (level_ / 4) ;
            }
            new_calculated_stat = (level_ / 2) + class_modifier;
        } else if ( sub_stat_name.first == "MagDef" ) {

            double class_modifier{0.0};
            if ( class_name_ == "Wizard" ) {
                class_modifier = (level_ / 4) ;
            } // yrita löytää mitä MNA tarkoittaa:
            new_calculated_stat = (level_ / 2) + class_modifier;

        } else if ( sub_stat_name.first == "AOEDefR" ) {
            // new_calculated_stat = level_ + mainstats_.at("STR");

        } else if ( sub_stat_name.first == "Evasion" ) {
            double class_modifier{0.0};
            if ( class_name_ == "Archer" ) {
                class_modifier = (level_ / 8);
            }
            new_calculated_stat = level_ + mainstats_.at("DEX") +
                    class_modifier;
        } else if ( sub_stat_name.first == "Block" ) {

        } else if ( sub_stat_name.first == "CritRes" ) {

        } else if ( sub_stat_name.first == "STA" ) {

        } else if ( sub_stat_name.first == "WL" ) {
            new_calculated_stat = 5000 + mainstats_.at("CON") * 5 +
                    mainstats_.at("STR") * 5;
        }

        sub_stats_.at(sub_stat_name.first) = int(new_calculated_stat + 0.5);
    }
}

int PlayableClasses::calculate_bonus(std::string stat_name) {
    int invested = total_invested_stats_.at(stat_name);
    if(1 <= invested && invested <= 50) {
        std::cout << "range 1-50" << std::endl;
        return (invested % 5 == 0) ? 1 : 0;
    } else if(50 < invested && invested <= 150) {
        std::cout << "range 50-150" << std::endl;
        return (invested % 4 == 0) ? 1 : 0;
    } else if(150 < invested && invested <= 300) {
        std::cout << "range 150-300" << std::endl;
       return (invested % 3 == 0) ? 1 : 0;
    } else if(301 < invested && invested <= 500) {
        std::cout << "range 301-500" << std::endl;
        return (invested % 2 == 0) ? 1 : 0;
    } else if(500 < invested){
        std::cout << "range 500" << std::endl;
        return 1;
    } else {
        return 0;
    }

}
void PlayableClasses::set_stat(std::string stat_name, int value) {
    std::cout << "" << std::endl;
    std::cout << "set_stat Alku:" << std::endl;
    std::cout << "ennen asetusta: " << stat_name << " v-> " << value << std::endl;
    std::cout << "ennen asetusta: " << stat_name << " -> " << mainstats_.at(stat_name) << std::endl;
    std::cout << "ennen asetusta: " << stat_name << " inv -> " << total_invested_stats_.at(stat_name) << std::endl;
    if ( value == mainstats_.at(stat_name) ) {
        mainstats_.at(stat_name) = value;
    } else if ( value < mainstats_.at(stat_name) ) {
        int bonus{calculate_bonus(stat_name)};
        mainstats_.at(stat_name) = value;
        mainstats_.at(stat_name) -= bonus;
        total_invested_stats_.at(stat_name) -= (1 + bonus);
        --level_;
    } else if ( value > mainstats_.at(stat_name) ) {
        mainstats_.at(stat_name) = value;
        total_invested_stats_.at(stat_name) += 1;
        int bonus{calculate_bonus(stat_name)};
        mainstats_.at(stat_name) += bonus;
        total_invested_stats_.at(stat_name) += bonus;
        ++level_;
    }
    std::cout << "jalkeen asetuksen: " << stat_name << " -> " << mainstats_.at(stat_name) << std::endl;
    std::cout << "jalkeen asetuksen: " << stat_name << " inv -> " << total_invested_stats_.at(stat_name) << std::endl;
    std::cout << "END" << std::endl;
    std::cout << "" << std::endl;
    calculate_sub_stats();
}
void PlayableClasses::set_rank(int rank) {
    rank_ = rank;
    double new_calculated_stat{0.0};
    new_calculated_stat = mainstats_.at("STR") * (pow(1.1, rank_));
    modifiers_.at("STR_Rank_Bonus") = new_calculated_stat;
    new_calculated_stat = mainstats_.at("INT") * (pow(1.1, rank_));
    modifiers_.at("INT_Rank_Bonus") = new_calculated_stat;

    /*
    // decreased by one:
    if ( rank < rank_ ) {
        new_calculated_stat = mainstats_.at("STR") / (pow(1.1, rank_));
        mainstats_.at("STR") = int(new_calculated_stat * (pow(1.1, rank)));
        new_calculated_stat = mainstats_.at("INT") / (pow(1.1, rank_));
        mainstats_.at("INT") = int(new_calculated_stat * (pow(1.1, rank)));
    } else {
        // increased by one:
        new_calculated_stat = mainstats_.at("STR") * 1.1;
        mainstats_.at("STR") = int(new_calculated_stat + 0.5);
        new_calculated_stat = mainstats_.at("INT") * 1.1;
        mainstats_.at("INT") = int(new_calculated_stat + 0.5);
    }
    */

    calculate_sub_stats();

}
int PlayableClasses::return_rank() const {
    return rank_;
}

