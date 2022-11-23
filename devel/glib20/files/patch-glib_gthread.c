--- glib/gthread.c.orig	2022-11-22 15:42:25.606200000 +0000
+++ glib/gthread.c	2022-11-22 17:01:58.781255000 +0000
@@ -1337,14 +1337,15 @@
  */
 void
 (g_once_init_leave) (volatile void *location,
-                     gsize          result)
+                     gpointer result)
 {
   gsize *value_location = (gsize *) location;
+  gpointer *result_location = (gpointer *) location;
 
   g_return_if_fail (g_atomic_pointer_get (value_location) == 0);
   g_return_if_fail (result != 0);
 
-  g_atomic_pointer_set (value_location, result);
+  g_atomic_pointer_set (result_location, result);
   g_mutex_lock (&g_once_mutex);
   g_return_if_fail (g_once_init_list != NULL);
   g_once_init_list = g_slist_remove (g_once_init_list, (void*) value_location);
