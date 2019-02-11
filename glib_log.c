#include <glib.h>

static void _dummy(const gchar *log_domain,
                     GLogLevelFlags log_level,
                     const gchar *message,
                     gpointer user_data )

{
  /* Dummy does nothing */
  return ;
}

int main() {
    /* set dummy for all levels */
    // g_log_set_handler(G_LOG_DOMAIN, G_LOG_LEVEL_MASK, _dummy, NULL);

    g_log_set_handler(G_LOG_DOMAIN, G_LOG_LEVEL_DEBUG,  g_log_default_handler, NULL);

    g_message("message logging");
    g_warning("warn logging");
    g_debug("debug logging");
    //g_error("error logging");
    g_log(NULL, G_LOG_LEVEL_INFO, "info logging");
    return 0;
}
