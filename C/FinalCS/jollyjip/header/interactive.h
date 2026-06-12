// Interaction-related functions
#define MAX_CHAR 200
#define MAX_ORDR 20
#define MAX_CLIENT 20

typedef struct
{
    char code[MAX_CHAR];
    char name[MAX_CHAR];
    char description[MAX_CHAR];
    float price;
    int qnt;
    float total;
} item;

typedef struct
{
    int num;
    item Items[MAX_ORDR];
    float billT;
    float discount;
    float billN;
    float tendered;
    float change;
} table;

int invalid_msg(char * inv_msg);

void removeNewline(char *str);

// Main Functions
int billSub(char * ordr_msg, char * inv_msg); // Billing Submodule

int fileMnt(); // File Maintenance

// billSubMod Sub-functions
int orderSys(char * ordr_msg, char * inv_msg);
void totalSales();

// fileMnt Sub-functions
void addRec();

void updateRec();
// Choices
void updateMenu();
void updatePrice();
