#include <glib.h>

int main(void) {
    GHashTable * freq = g_hash_table_new(g_int_hash, g_int_equal);
    for (int i = 0; i < 10; i++) {
        g_hash_table_insert(freq, GINT_TO_POINTER(i), GINT_TO_POINTER(0));
    }
    g_hash_table_destroy(freq);
}
