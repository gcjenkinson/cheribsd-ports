--- glib/ghash.c.orig	2022-11-21 17:13:46.834722000 +0000
+++ glib/ghash.c	2022-11-21 17:12:47.865983000 +0000
@@ -290,7 +290,7 @@
   gpointer     dummy2;
   gint         position;
   gboolean     dummy3;
-  gint         version;
+  gintptr      version;
 } RealIter;
 
 G_STATIC_ASSERT (sizeof (GHashTableIter) == sizeof (RealIter));
