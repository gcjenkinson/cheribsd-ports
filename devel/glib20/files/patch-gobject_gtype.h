--- gobject/gtype.h.orig	2022-11-23 14:17:53.206840000 +0000
+++ gobject/gtype.h	2022-11-23 14:13:37.539097000 +0000
@@ -396,11 +396,15 @@
  * A numerical value which represents the unique identifier of a registered
  * type.
  */
+#if 1
+typedef gintptr                         GType;
+#else
 #if     GLIB_SIZEOF_SIZE_T != GLIB_SIZEOF_LONG || !defined __cplusplus
 typedef gsize                           GType;
 #else   /* for historic reasons, C++ links against gulong GTypes */
 typedef gulong                          GType;
 #endif
+#endif
 typedef struct _GValue                  GValue;
 typedef union  _GTypeCValue             GTypeCValue;
 typedef struct _GTypePlugin             GTypePlugin;
@@ -1860,7 +1864,7 @@
  * GType
  * gtk_gadget_get_type (void)
  * {
- *   static gsize static_g_define_type_id = 0;
+ *   static gintptr static_g_define_type_id = 0;
  *   if (g_once_init_enter (&static_g_define_type_id))
  *     {
  *       GType g_define_type_id =
@@ -2137,7 +2141,7 @@
 GType \
 type_name##_get_type (void) \
 { \
-  static gsize static_g_define_type_id = 0;
+  static gintptr static_g_define_type_id = 0;
   /* Prelude goes here */
 
 /* Added for _G_DEFINE_TYPE_EXTENDED_WITH_PRELUDE */
@@ -2183,7 +2187,7 @@
 GType \
 type_name##_get_type (void) \
 { \
-  static gsize static_g_define_type_id = 0; \
+  static gintptr static_g_define_type_id = 0; \
   if (g_once_init_enter (&static_g_define_type_id)) \
     { \
       GType g_define_type_id = \
@@ -2273,7 +2277,7 @@
 GType \
 type_name##_get_type (void) \
 { \
-  static gsize static_g_define_type_id = 0; \
+  static gintptr static_g_define_type_id = 0; \
   if (g_once_init_enter (&static_g_define_type_id)) \
     { \
       GType g_define_type_id = type_name##_get_type_once (); \
@@ -2310,7 +2314,7 @@
 GType \
 type_name##_get_type (void) \
 { \
-  static gsize static_g_define_type_id = 0; \
+  static gintptr static_g_define_type_id = 0; \
   if (g_once_init_enter (&static_g_define_type_id)) \
     { \
       GType g_define_type_id = type_name##_get_type_once (); \
@@ -2363,7 +2367,7 @@
 GType \
 type_name##_get_type (void) \
 { \
-  static gsize static_g_define_type_id = 0; \
+  static gintptr static_g_define_type_id = 0; \
   if (g_once_init_enter (&static_g_define_type_id)) \
     { \
       GType g_define_type_id = type_name##_get_type_once (); \
