--- glib/gtimezone.c.orig	2022-11-22 12:39:01.950491000 +0000
+++ glib/gtimezone.c	2022-11-22 12:40:07.938307000 +0000
@@ -1965,7 +1965,7 @@
 g_time_zone_new_utc (void)
 {
   static GTimeZone *utc = NULL;
-  static gsize initialised;
+  static gintptr initialised;
 
   if (g_once_init_enter (&initialised))
     {
