--- gio/gsettingsschema.c.orig	2022-11-23 15:15:04.807259000 +0000
+++ gio/gsettingsschema.c	2022-11-23 15:15:48.300099000 +0000
@@ -337,7 +337,7 @@
 static void
 initialise_schema_sources (void)
 {
-  static gsize initialised;
+  static gintptr initialised;
 
   /* need a separate variable because 'schema_sources' may legitimately
    * be null if we have zero valid schema sources
@@ -847,7 +847,7 @@
 
 static gchar **non_relocatable_schema_list;
 static gchar **relocatable_schema_list;
-static gsize schema_lists_initialised;
+static gintptr schema_lists_initialised;
 
 static void
 ensure_schema_lists (void)
