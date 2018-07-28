
/**
 * @file    Engine\TRB\History.hpp
 * @author  Yvan Burrie
 * @date    2018/02/22
 * @version 1.0
 */

class TRIBE_History_Info
{
public:

    struct TRIBE_History_Entry *history;
    struct TRIBE_History_Events *events;
    int number_of_events;
    int number_of_entries;
    int max_number_of_entries;

    TRIBE_History_Info(int infile);

    ~TRIBE_History_Info();

    void save(int outfile);

    void load(int infile);

    void add_history_entry(char history_type, char entry);
    int get_history_entry_num();
    char get_history_entry(char history_type, int time);
    void add_history_event(char history_event);
    int get_history_event_num();
    char get_history_event(int number, char *event, int *time);
    char get_history_event(int time_slice, char *event);
};

struct TRIBE_History_Entry
{
    char population;
};

struct TRIBE_History_Events
{
    char event;
    int time;
    int world_time;
    TRIBE_History_Events *next;
};
