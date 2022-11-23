--- glib/gmacros.h.orig	2022-11-22 18:37:52.567377000 +0000
+++ glib/gmacros.h	2022-11-22 18:36:49.136592000 +0000
@@ -903,8 +903,8 @@
 
 /* Macros by analogy to GINT_TO_POINTER, GPOINTER_TO_INT
  */
-#define GPOINTER_TO_SIZE(p)	((gsize) (p))
-#define GSIZE_TO_POINTER(s)	((gpointer) (gsize) (s))
+#define GPOINTER_TO_SIZE(p)	((gintptr) (gsize) (p))
+#define GSIZE_TO_POINTER(s)	((gpointer) (gintptr) (s))
 
 /* Provide convenience macros for handling structure
  * fields through their offsets.
