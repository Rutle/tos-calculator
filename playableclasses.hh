#ifndef PLAYABLECLASSES_HH
#define PLAYABLECLASSES_HH

#include <map>
#include <string>

class PlayableClasses {
    public:
        PlayableClasses();
        PlayableClasses(const std::map<std::string, int>& stats,
                        const std::map<std::string, double>& mods,
                        int level, std::string class_name);
        PlayableClasses(const PlayableClasses& sijoitus);

        int return_stat(const std::string& stat_name) const;
        int return_level() const;
        void add_class_stats(const std::map<std::string, int>& stats,
                             const std::map<std::string, double>& mods,
                             int level, std::string class_name);
        void reset_stats();
        void set_stat(std::string stat_name, int value);


    private:
        std::map<std::string, int> mainstats_;
        std::map<std::string, double> modifiers_;
        int level_;
        std::map<std::string, int> sub_stats_;
        std::string class_name_;
        void calculate_sub_stats();

};

#endif // PLAYABLECLASSES_HH
