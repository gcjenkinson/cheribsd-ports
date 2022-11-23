--- glib/gmessages.c.orig	2022-11-22 12:27:40.768544000 +0000
+++ glib/gmessages.c	2022-11-22 12:28:04.927840000 +0000
@@ -2767,7 +2767,7 @@
                       gsize            n_fields,
                       gpointer         user_data)
 {
-  static gsize initialized = 0;
+  static gintptr initialized = 0;
   static gboolean stderr_is_journal = FALSE;
 
   g_return_val_if_fail (fields != NULL, G_LOG_WRITER_UNHANDLED);
