--- gio/gfileenumerator.c.orig	2022-11-23 15:09:03.903740000 +0000
+++ gio/gfileenumerator.c	2022-11-23 15:09:32.184414000 +0000
@@ -636,7 +636,7 @@
 
   static GQuark cached_info_quark;
   static GQuark cached_child_quark;
-  static gsize quarks_initialized;
+  static gintptr quarks_initialized;
 
   g_return_val_if_fail (direnum != NULL, FALSE);
   g_return_val_if_fail (out_info != NULL || out_child != NULL, FALSE);
