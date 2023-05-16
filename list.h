//somente assinatura dos ADT (das funções)
typedef struct list List;

List* list_create();
void list_free(List* list); //disgraçado
void list_display(List* list);
void list_add(List* list, int value); //poder ser value -> inteiro, char, float, struct, string (kk)
int list_remove(List* list, int index);
void list_set(List* list, int index, int value);
void list_insert(List* list, int index, int value);
int list_get (List* list, int index);