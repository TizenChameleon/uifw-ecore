/*
 * vim:ts=8:sw=3:sts=8:noexpandtab:cino=>5n-3f0^-2{2
 */

#ifndef _ECORE_IMF_H
#define _ECORE_IMF_H

#include <Evas.h>
#include <keydefs.h>
#include <Ecore_IMF_Input_Panel_Key.h>

#ifdef EAPI
# undef EAPI
#endif

#ifdef _WIN32
# ifdef EFL_ECORE_IMF_BUILD
#  ifdef DLL_EXPORT
#   define EAPI __declspec(dllexport)
#  else
#   define EAPI
#  endif /* ! DLL_EXPORT */
# else
#  define EAPI __declspec(dllimport)
# endif /* ! EFL_ECORE_IMF_BUILD */
#else
# ifdef __GNUC__
#  if __GNUC__ >= 4
#   define EAPI __attribute__ ((visibility("default")))
#  else
#   define EAPI
#  endif
# else
#  define EAPI
# endif
#endif /* ! _WIN32 */

/* Faked 'bool'.  */
#ifndef __cplusplus
#ifndef bool
#define bool int
#define FALSE 0
#define TRUE 1
#endif
#endif

/**
 * @file Ecore_IMF.h
 * @brief The file that provides the ISF IMCONTROL Structures and APIs
 * @version   1.0
 * @ingroup   Ecore_IMF_Context_IMControl_Group
 */

#ifdef __cplusplus
extern "C" {
#endif

   typedef struct 
     {
	int x;				/**< x-coordinate of ISE window from left edge of screen*/
	int y;				/**< y-coordinate of ISE window from top edge of screen*/
	int width;			/**< width of ISE window from x- coordinate*/
	int height;			/**< height of ISE window from y- coordinate*/
     } ISE_RECT;

   /* ecore_imf_context_ise_state_add_listener() flag */
   typedef enum 
     {
	ISE_STATE_EVENT,                /**< ISE STATE Event */
	ISE_MODE_EVENT,                 /**< ISE MODE Event */
	ISE_LANGUAGE_EVENT,             /**< ISE LANGUAGE Event */
	ISE_SHIFT_MODE_EVENT,           /**< ISE SHIFT MODE */
	ISE_PREEDIT_MODE_EVENT,         /**< ISE PREEDIT MODE */
	ISE_COMPLETION_MODE_EVENT,      /**< ISE COMPLETION MODE */
	ISE_CUSTOM_INPUT_MODE_EVENT,    /**< ISE CUSTOM INPUT MODE */

	ISE_PRIVATE_CONTEXT_01,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_02,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_03,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_04,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_05,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_06,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_07,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_08,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_09,  /**< ISE PRIVATE CONTEXT */
	ISE_PRIVATE_CONTEXT_10,  /**< ISE PRIVATE CONTEXT */
	ISE_EVENT_INVALID
     } ISE_EVENT;

   typedef enum 
     {
	ISE_STATE_SHOW,         /**< Show ISE */
	ISE_STATE_SHOW_ALWAYS,  /**< Show ISE always*/
	ISE_STATE_HIDE,         /**< Hide ISE */
	ISE_STATE_INVALID
     } ISE_STATE;

   typedef enum 
     {
	ISE_MODE_NATIVE,        /**< Follow current locale mode */
	ISE_MODE_ENGLISH,       /**< English mode*/
	ISE_MODE_NUMBER,        /**< Number mode*/
	ISE_MODE_INVALID
     } ISE_MODE;

   typedef enum 
     {
	ISE_LAYOUT_NORMAL,          /**< default 4x4 layout */
	ISE_LAYOUT_NUMBER,          /**< number layout*/
	ISE_LAYOUT_EMAIL,           /**< Email layout*/
	ISE_LAYOUT_URL,             /**< URL layout*/
	ISE_LAYOUT_PHONENUMBER,     /**< Phone Number layout*/
	ISE_LAYOUT_CUSTOM_1 = 10,   /* Reserved for future use */
	ISE_LAYOUT_CUSTOM_2,
	ISE_LAYOUT_CUSTOM_3,
	ISE_LAYOUT_CUSTOM_4,
	ISE_LAYOUT_CUSTOM_5,
	ISE_LAYOUT_CUSTOM_6,
	ISE_LAYOUT_CUSTOM_7,
	ISE_LAYOUT_CUSTOM_8,
	ISE_LAYOUT_CUSTOM_9,
	ISE_LAYOUT_CUSTOM_10,
	ISE_LAYOUT_INVALID
     } ISE_LAYOUT;

   typedef enum 
     {
	ISE_LANG_ENGLISH,   /**< English */
	ISE_LANG_FRENCH,    /**< French */
	ISE_LANG_SPANISH,   /**< Spanish */
	ISE_LANG_DUTCH,     /**< Dutch */
	ISE_LANG_GERMAN,    /**< German */
	ISE_LANG_ITALIAN,   /**< Italian */
	ISE_LANG_PORTUGUESE,/**< Portuguese */
	ISE_LANG_TURKISH,   /**< Turkish */
	ISE_LANG_KOREAN,    /**< Korean */
	ISE_LANG_CHINESE,   /**< Chinese */
	ISE_LANG_JAPANESE,  /**< Japanese */
	ISE_LANG_HINDI,     /**< Hindi */
	ISE_LANG_THAI,      /**< Thai */
	ISE_LANG_GREEK,     /**< Greek */
	ISE_LANG_INVALID
     } ISE_LANG;

   typedef enum 
     {
	ISE_AUTOCORRECTION_DEFAULT,
	ISE_AUTOCORRECTION_NO,
	ISE_AUTOCORRECTION_YES,
	ISE_AUTOCORRECTION_INVALID
     } ISE_AUTOCORRECTION;
    
    /* As of now this ISE_STYLE is not decided -- Not supported for now --*/
   typedef struct 
     {
	bool fUseImEffect;  /**< whether use Im effect or not */	
     } ISE_STYLE;

   /* Events sent by the Input Method */
   typedef struct _Ecore_IMF_Event_Preedit_Start      Ecore_IMF_Event_Preedit_Start;
   typedef struct _Ecore_IMF_Event_Preedit_End        Ecore_IMF_Event_Preedit_End;
   typedef struct _Ecore_IMF_Event_Preedit_Changed    Ecore_IMF_Event_Preedit_Changed;
   typedef struct _Ecore_IMF_Event_Commit             Ecore_IMF_Event_Commit;
   typedef struct _Ecore_IMF_Event_Delete_Surrounding Ecore_IMF_Event_Delete_Surrounding;

   /* Events to filter */
   typedef struct _Ecore_IMF_Event_Mouse_Down         Ecore_IMF_Event_Mouse_Down;
   typedef struct _Ecore_IMF_Event_Mouse_Up           Ecore_IMF_Event_Mouse_Up;
   typedef struct _Ecore_IMF_Event_Mouse_In           Ecore_IMF_Event_Mouse_In;
   typedef struct _Ecore_IMF_Event_Mouse_Out          Ecore_IMF_Event_Mouse_Out;
   typedef struct _Ecore_IMF_Event_Mouse_Move         Ecore_IMF_Event_Mouse_Move;
   typedef struct _Ecore_IMF_Event_Mouse_Wheel        Ecore_IMF_Event_Mouse_Wheel;
   typedef struct _Ecore_IMF_Event_Key_Down           Ecore_IMF_Event_Key_Down;
   typedef struct _Ecore_IMF_Event_Key_Up             Ecore_IMF_Event_Key_Up;
   typedef union  _Ecore_IMF_Event                    Ecore_IMF_Event;

   typedef struct _Ecore_IMF_Context                  Ecore_IMF_Context;                  /**< An Input Method Context */
   typedef struct _Ecore_IMF_Context_Class            Ecore_IMF_Context_Class;            /**< An Input Method Context class */
   typedef struct _Ecore_IMF_Context_Info             Ecore_IMF_Context_Info;             /**< An Input Method Context info */

   EAPI extern int ECORE_IMF_EVENT_PREEDIT_START;
   EAPI extern int ECORE_IMF_EVENT_PREEDIT_END;
   EAPI extern int ECORE_IMF_EVENT_PREEDIT_CHANGED;
   EAPI extern int ECORE_IMF_EVENT_COMMIT;
   EAPI extern int ECORE_IMF_EVENT_DELETE_SURROUNDING;

   typedef enum
     {
	ECORE_IMF_EVENT_MOUSE_DOWN,
	ECORE_IMF_EVENT_MOUSE_UP,
	ECORE_IMF_EVENT_MOUSE_IN,
	ECORE_IMF_EVENT_MOUSE_OUT,
	ECORE_IMF_EVENT_MOUSE_MOVE,
	ECORE_IMF_EVENT_MOUSE_WHEEL,
	ECORE_IMF_EVENT_KEY_DOWN,
	ECORE_IMF_EVENT_KEY_UP
     } Ecore_IMF_Event_Type;

   typedef enum
     {
	ECORE_IMF_KEYBOARD_MODIFIER_NONE  = 0,      /**< No active modifiers */
	ECORE_IMF_KEYBOARD_MODIFIER_CTRL  = 1 << 0, /**< "Control" is pressed */
	ECORE_IMF_KEYBOARD_MODIFIER_ALT   = 1 << 1, /**< "Alt" is pressed */
	ECORE_IMF_KEYBOARD_MODIFIER_SHIFT = 1 << 2, /**< "Shift" is pressed */
	ECORE_IMF_KEYBOARD_MODIFIER_WIN   = 1 << 3  /**< "Win" (between "Ctrl" and "Alt") is pressed */
     } Ecore_IMF_Keyboard_Modifiers;

   typedef enum
     {
	ECORE_IMF_KEYBOARD_LOCK_NONE      = 0,      /**< No locks are active */
	ECORE_IMF_KEYBOARD_LOCK_NUM       = 1 << 0, /**< "Num" lock is active */
	ECORE_IMF_KEYBOARD_LOCK_CAPS      = 1 << 1, /**< "Caps" lock is active */
	ECORE_IMF_KEYBOARD_LOCK_SCROLL    = 1 << 2  /**< "Scroll" lock is active */
     } Ecore_IMF_Keyboard_Locks;

   typedef enum
     {
	ECORE_IMF_MOUSE_NONE              = 0,      /**< A single click */
	ECORE_IMF_MOUSE_DOUBLE_CLICK      = 1 << 0, /**< A double click */
	ECORE_IMF_MOUSE_TRIPLE_CLICK      = 1 << 1  /**< A triple click */
     } Ecore_IMF_Mouse_Flags;

   typedef enum
     {
	ECORE_IMF_INPUT_MODE_ALPHA        = 1 << 0,
	ECORE_IMF_INPUT_MODE_NUMERIC      = 1 << 1,
	ECORE_IMF_INPUT_MODE_SPECIAL      = 1 << 2,
	ECORE_IMF_INPUT_MODE_HEXA         = 1 << 3,
	ECORE_IMF_INPUT_MODE_TELE         = 1 << 4,
	ECORE_IMF_INPUT_MODE_FULL         = (ECORE_IMF_INPUT_MODE_ALPHA | ECORE_IMF_INPUT_MODE_NUMERIC | ECORE_IMF_INPUT_MODE_SPECIAL),
	ECORE_IMF_INPUT_MODE_INVISIBLE    = 1 << 29,
	ECORE_IMF_INPUT_MODE_AUTOCAP      = 1 << 30
     } Ecore_IMF_Input_Mode;

   struct _Ecore_IMF_Event_Preedit_Start
     {
	Ecore_IMF_Context *ctx;
     };

   struct _Ecore_IMF_Event_Preedit_End
     {
	Ecore_IMF_Context *ctx;
     };

   struct _Ecore_IMF_Event_Preedit_Changed
     {
	Ecore_IMF_Context *ctx;
     };

   struct _Ecore_IMF_Event_Commit
     {
	Ecore_IMF_Context *ctx;
	char *str;
     };

   struct _Ecore_IMF_Event_Delete_Surrounding
     {
	Ecore_IMF_Context *ctx;
	int offset;
	int n_chars;
     };

   struct _Ecore_IMF_Event_Mouse_Down
     {
	int button;                             /**< The button which has been pressed */
	struct {
	     int x, y;
	} output;
	struct {
	     int x, y;
	} canvas;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	Ecore_IMF_Mouse_Flags        flags;     /**< The flags corresponding the mouse click (single, double or triple click) */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Mouse_Up
     {
	int button;                             /**< The button which has been pressed */
	struct {
	     int x, y;
	} output;
	struct {
	     int x, y;
	} canvas;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	Ecore_IMF_Mouse_Flags        flags;     /**< The flags corresponding the mouse click (single, double or triple click) */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Mouse_In
     {
	int buttons;
	struct {
	     int x, y;
	} output;
	struct {
	     int x, y;
	} canvas;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Mouse_Out
     {
	int buttons;
	struct {
	     int x, y;
	} output;
	struct {
	     int x, y;
	} canvas;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Mouse_Move
     {
	int buttons;
	struct {
	     struct {
		  int x, y;
	     } output;
	     struct {
		  int x, y;
	     } canvas;
	} cur, prev;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Mouse_Wheel
     {
	int direction;                         /* 0 = default up/down wheel */
	int z;                                 /* ...,-2,-1 = down, 1,2,... = up */
	struct {
	     int x, y;
	} output;
	struct {
	     int x, y;
	} canvas;
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   struct _Ecore_IMF_Event_Key_Down
     {
	const char                  *keyname;   /**< The string name of the key pressed */
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	const char                  *key;       /**< The logical key : (eg shift+1 == exclamation) */
	const char                  *string;    /**< A UTF8 string if this keystroke has produced a visible string to be ADDED */
	const char                  *compose;   /**< A UTF8 string if this keystroke has modified a string in the middle of being composed - this string replaces the previous one */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
   };

   struct _Ecore_IMF_Event_Key_Up
     {
	const char                  *keyname;   /**< The string name of the key pressed */
	Ecore_IMF_Keyboard_Modifiers modifiers; /**< The keyboard modifiers active when the event has been emitted */
	Ecore_IMF_Keyboard_Locks     locks;     /**< The keyboard locks active when the event has been emitted */
	const char                  *key;       /**< The logical key : (eg shift+1 == exclamation) */
	const char                  *string;    /**< A UTF8 string if this keystroke has produced a visible string to be ADDED */
	const char                  *compose;   /**< A UTF8 string if this keystroke has modified a string in the middle of being composed - this string replaces the previous one */
	unsigned int                 timestamp; /**< The timestamp when the event occured */
     };

   union _Ecore_IMF_Event
     {
	Ecore_IMF_Event_Mouse_Down mouse_down;
	Ecore_IMF_Event_Mouse_Up mouse_up;
	Ecore_IMF_Event_Mouse_In mouse_in;
	Ecore_IMF_Event_Mouse_Out mouse_out;
	Ecore_IMF_Event_Mouse_Move mouse_move;
	Ecore_IMF_Event_Mouse_Wheel mouse_wheel;
	Ecore_IMF_Event_Key_Down key_down;
	Ecore_IMF_Event_Key_Up key_up;
     };

   struct _Ecore_IMF_Context_Class
     {
	void (*add)                 (Ecore_IMF_Context *ctx);
	void (*del)                 (Ecore_IMF_Context *ctx);
	void (*client_window_set)   (Ecore_IMF_Context *ctx, void *window);
	void (*client_canvas_set)   (Ecore_IMF_Context *ctx, void *canvas);
	void (*show)                (Ecore_IMF_Context *ctx);
	void (*hide)                (Ecore_IMF_Context *ctx);
	void (*preedit_string_get)  (Ecore_IMF_Context *ctx, char **str, int *cursor_pos);
	void (*focus_in)            (Ecore_IMF_Context *ctx);
	void (*focus_out)           (Ecore_IMF_Context *ctx);
	void (*reset)               (Ecore_IMF_Context *ctx);
	void (*cursor_position_set) (Ecore_IMF_Context *ctx, int cursor_pos);
	void (*use_preedit_set)     (Ecore_IMF_Context *ctx, int use_preedit);
	void (*input_mode_set)      (Ecore_IMF_Context *ctx, Ecore_IMF_Input_Mode input_mode);
	int  (*filter_event)        (Ecore_IMF_Context *ctx, Ecore_IMF_Event_Type type, Ecore_IMF_Event *event);

	/* IM Control APIs */
	int (*ise_show)	              (Ecore_IMF_Context *ctx, Evas_Object *obj, ISE_STATE state);
	int (*ise_hide)	              (Ecore_IMF_Context *ctx);
	int (*ise_control_panel_show) (Ecore_IMF_Context *ctx);
	int (*ise_control_panel_hide) (Ecore_IMF_Context *ctx);

	int (*ise_set_mode)           (Ecore_IMF_Context *ctx, ISE_MODE mode);
	int (*ise_get_mode)           (Ecore_IMF_Context *ctx, ISE_MODE *mode);
	int (*ise_set_language)       (Ecore_IMF_Context *ctx, ISE_LANG lang);
	int (*ise_get_language)       (Ecore_IMF_Context *ctx, ISE_LANG *lang);
	int (*ise_get_ise_language)   (Ecore_IMF_Context *ctx, const char* ise_name, char*** langlist);
	int (*ise_set_isf_language)   (Ecore_IMF_Context *ctx, const char* lang);
	
	int (*ise_set_imdata)         (Ecore_IMF_Context *ctx, const char* data,int len);
	int (*ise_get_imdata)         (Ecore_IMF_Context *ctx, char* data,int *len);
	int (*ise_set_style)          (Ecore_IMF_Context *ctx, ISE_STYLE style);
	int (*ise_get_style)          (Ecore_IMF_Context *ctx, ISE_STYLE *style);
	int (*ise_get_window_rect)    (Ecore_IMF_Context *ctx, ISE_RECT *rect);
	int (*ise_set_private_key)    (Ecore_IMF_Context *ctx, int layout_index, int key_index, const char* label, const char* value);
	int (*ise_set_private_key_by_image) (Ecore_IMF_Context *ctx, int layout_index, int key_index, const char *img_path, const char* value);
	int (*ise_set_layout)         (Ecore_IMF_Context *ctx, ISE_LAYOUT layout);
	int (*ise_get_layout)         (Ecore_IMF_Context *ctx, ISE_LAYOUT  *layout);
	int (*ise_reset)              (Ecore_IMF_Context *ctx); /* Same as reset to default property*/
	
	int (*ise_set_screen_orientation) (Ecore_IMF_Context *ctx, int orientation);
	int (*ise_get_active_isename)     (Ecore_IMF_Context *ctx, char* name);
	int (*ise_set_active_ise_by_name) (Ecore_IMF_Context *ctx, const char* name);
	int (*ise_set_active_ise_by_uuid) (Ecore_IMF_Context *ctx, const char* uuid);
	int (*ise_get_iselist)            (Ecore_IMF_Context *ctx, char*** iselist);
	int (*ise_get_ise_state)          (Ecore_IMF_Context *ctx, ISE_STATE *state);

	/* CallBack APIs  */
	int (*ise_state_add_listener)   (Ecore_IMF_Context *ctx, void (*plistenerCallBackFunc) (ISE_EVENT,int), void *data); /**< This API will be depricated */
	int (*ise_state_remove_listener)(Ecore_IMF_Context *ctx, int listener_id); /**< This API will be depricated */
	int (*ise_state_change_listener)(Ecore_IMF_Context *ctx, void (*plistenerCallBackFunc) (ISE_EVENT,int)); /**< This API will be depricated */
	void (*ise_event_callback_set)  (Ecore_IMF_Context *ctx, void (*plistenerCallBackFunc) (void *,ISE_EVENT,int), void *data);
	int (*ise_initialize)(Ecore_IMF_Context *ctx, Evas_Object * mainwindow);
	const char * (*get_focused_preedit_string)(Ecore_IMF_Context *ctx);

	int (*ise_set_disable_key)      (Ecore_IMF_Context *ctx, int layout_index, int key_index, Eina_Bool disabled);
     };

   struct _Ecore_IMF_Context_Info
     {
	const char *id;              /* ID */
	const char *description;     /* Human readable description */
	const char *default_locales; /* Languages for which this context is the default, separated by : */
	const char *canvas_type;     /* The canvas type used by the input method. Eg.: evas */
	int         canvas_required; /* Whether the canvas usage is required for this input method */
     };

   EAPI int                           ecore_imf_init(void);
   EAPI int                           ecore_imf_shutdown(void);

   EAPI void                          ecore_imf_module_register(const Ecore_IMF_Context_Info *info, Ecore_IMF_Context *(*imf_module_create)(void), Ecore_IMF_Context *(*imf_module_exit)(void));

   EAPI Eina_List                    *ecore_imf_context_available_ids_get(void);
   EAPI Eina_List                    *ecore_imf_context_available_ids_by_canvas_type_get(const char *canvas_type);
   EAPI const char                   *ecore_imf_context_default_id_get(void);
   EAPI const char                   *ecore_imf_context_default_id_by_canvas_type_get(const char *canvas_type);
   EAPI const Ecore_IMF_Context_Info *ecore_imf_context_info_by_id_get(const char *id);

   EAPI Ecore_IMF_Context            *ecore_imf_context_add(const char *id);
   EAPI const Ecore_IMF_Context_Info *ecore_imf_context_info_get(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_del(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_client_window_set(Ecore_IMF_Context *ctx, void *window);
   EAPI void                          ecore_imf_context_client_canvas_set(Ecore_IMF_Context *ctx, void *canvas);
   EAPI void                          ecore_imf_context_show(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_hide(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_preedit_string_get(Ecore_IMF_Context *ctx, char **str, int *cursor_pos);
   EAPI void                          ecore_imf_context_focus_in(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_focus_out(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_reset(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_cursor_position_set(Ecore_IMF_Context *ctx, int cursor_pos);
   EAPI void                          ecore_imf_context_use_preedit_set(Ecore_IMF_Context *ctx, int use_preedit);
   EAPI void                          ecore_imf_context_retrieve_surrounding_callback_set(Ecore_IMF_Context *ctx, int (*func)(void *data, Ecore_IMF_Context *ctx, char **text, int *cursor_pos), const void *data);
   EAPI void                          ecore_imf_context_input_mode_set(Ecore_IMF_Context *ctx, Ecore_IMF_Input_Mode input_mode);
   EAPI Ecore_IMF_Input_Mode          ecore_imf_context_input_mode_get(Ecore_IMF_Context *ctx);
   EAPI int                           ecore_imf_context_filter_event(Ecore_IMF_Context *ctx, Ecore_IMF_Event_Type type, Ecore_IMF_Event *event);

   /* plugin specific functions */
   EAPI Ecore_IMF_Context            *ecore_imf_context_new(const Ecore_IMF_Context_Class *ctxc);
   EAPI void                          ecore_imf_context_data_set(Ecore_IMF_Context *ctx, void *data);
   EAPI void                         *ecore_imf_context_data_get(Ecore_IMF_Context *ctx);
   EAPI int                           ecore_imf_context_surrounding_get(Ecore_IMF_Context *ctx, char **text, int *cursor_pos);
   EAPI void                          ecore_imf_context_preedit_start_event_add(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_preedit_end_event_add(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_preedit_changed_event_add(Ecore_IMF_Context *ctx);
   EAPI void                          ecore_imf_context_commit_event_add(Ecore_IMF_Context *ctx, const char *str);
   EAPI void                          ecore_imf_context_delete_surrounding_event_add(Ecore_IMF_Context *ctx, int offset, int n_chars);

   /**
    * @defgroup Ecore_IMF_Context_IMControl_Group Ecore Input Method Context IMControl Functions
    *
    * Functions that should be used by EFL applications to operate ISF and ISE.
    */

   /**
    * Get imf_context to map to real loaded context APIs, e.g. APIs provided by isf context or other context.
    * In this case, the return context is used as the 1st input paramete of all IMControl APIs.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */    
   EAPI Ecore_IMF_Context* ecore_get_imf_context();
   
   /**
    * Show the current active ISE with given state.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param obj evas object to be operated when ISE shows
    * @param state see ISE_STATE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     Evas_Object *en = obj;
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     if(imf_context)
    *     {    
    *         //Note: this API MUST be called before calling     ecore_imf_context_ise_set_** APIs and ecore_imf_context_ise_show.
    *         ecore_imf_context_ise_reset (imf_context);   
    *         //show ise window
    *         ecore_imf_context_ise_show (imf_context, en, state);      
    *     }
    *     ecore_imf_shutdown();
    * }
    *
    * static void entry_application(appdata * ad)
    * {
    *     Evas_Object *en;
    *     en = elm_entry_add(ad->win_main);
    *     evas_object_smart_callback_add(en, "clicked", entry_clicked_cb, ad);
    * }
    *
    * @endcode
    */ 
   EAPI void ecore_imf_context_ise_show(Ecore_IMF_Context *ctx,Evas_Object *obj, ISE_STATE state);

   /**
    * Hide the current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    * static void entry_application(appdata * ad)
    * {
    *     Evas_Object *en;
    *     en = elm_entry_add(ad->win_main);
    *     evas_object_smart_callback_add(en, "clicked", button_clicked_cb,en);
    * }
    * static void button_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     Evas_Object *en = data;
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     if(imf_context)
    *     {    
    *         ecore_imf_context_ise_hide (imf_context, en, state);      
    *     }
    *     ecore_imf_shutdown();
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_hide(Ecore_IMF_Context *ctx);

   /**
    * Show ISE control panel.
    * @param ctx context used to map real loaded APIs
    * @ingroup Ecore_IMF_Context_IMControl_Group
    *
    * ISE control panel shows ISE list and provides setup of each ISE
    * THIS API IS NOT SUPPORTED NOW
    */    
   EAPI void ecore_imf_context_ise_control_panel_show (Ecore_IMF_Context *ctx);

   /**
    * Hide ISE control panel.
    * @param ctx context used to map real loaded APIs
    * @ingroup Ecore_IMF_Context_IMControl_Group
    *
    * ISE control panel shows ISE list and provides setup of each ISE
    * THIS API IS NOT SUPPORTED NOW
    */    
   EAPI void ecore_imf_context_ise_control_panel_hide (Ecore_IMF_Context *ctx);

   /**
    * Set ISE Mode before show ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * @param ctx context used to map real loaded APIs
    * @param mode see ISE_MODE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_MODE mode = ISE_MODE_NUMBER;
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_mode (imf_context, mode);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    * 
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_mode  (Ecore_IMF_Context *ctx, ISE_MODE mode);

   /**
    * Get ISE Mode of current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param mode see ISE_MODE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_MODE mode;
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_get_mode (imf_context, &mode); 
    *         //here u can see what the current mode is.
    *         ecore_imf_context_ise_reset (imf_context);
    *         mode = ISE_MODE_NUMBER;
    *         ecore_imf_context_ise_set_mode (imf_context, mode);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    * 
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_mode  (Ecore_IMF_Context *ctx, ISE_MODE *mode);

   /**
    * Set ISE Language before show ISE.
    * @param ctx context used to map real loaded APIs
    * @param lang see ISE_LANG
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * THIS API IS NOT SUPPORTED NOW
    */    
   EAPI void ecore_imf_context_ise_set_language (Ecore_IMF_Context *ctx, ISE_LANG lang);

   /**
    * Get ISE Language of current active ISE.
    * @param ctx context used to map real loaded APIs
    * @param lang see ISE_LANG
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * THIS API IS NOT SUPPORTED NOW
    */
   EAPI void ecore_imf_context_ise_get_language (Ecore_IMF_Context *ctx, ISE_LANG *lang);

   /**
    * Get ISE Language of given ISE. -- Not supported for now --
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EAPI int ecore_imf_context_ise_get_ise_language (Ecore_IMF_Context *ctx, const char* ise_name, char ***langlist);

   /**
    * Set ISF Language. -- Not supported for now --
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EAPI void ecore_imf_context_ise_set_isf_language (Ecore_IMF_Context *ctx, const char* lang);
   
   /**
    * Set ISE Specific data before show ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * @param ctx context used to map real loaded APIs
    * @param data data pointer
    * @param len data length
    * @ingroup Ecore_IMF_Context_IMControl_Group
    *
    * this API is used by applications to deliver specific data to ISE. 
    * the data format MUST be negotiated by both application and ISE negotiate.
    *
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     char *im_data="application sample imdata";
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_imdata (imf_context, im_data, strlen(im_data)+1);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_imdata       (Ecore_IMF_Context *ctx, const char * data, int len);

   /**
    * Get ISE Specific data of current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param data data pointer
    * @param len data length
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     int len = 256;
    *     char *im_data = (char*) malloc (len);
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_get_imdata (imf_context, im_data, &len);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_imdata       (Ecore_IMF_Context *ctx, char * data,int *len);

   /**
    * Set ISE Style before show ISE.  -- Not supported for now --
    * @param ctx context used to map real loaded APIs
    * @param style see ISE_STYLE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * THIS API IS NOT SUPPORTED NOW
    */    
   EAPI void ecore_imf_context_ise_set_style        (Ecore_IMF_Context *ctx, ISE_STYLE style);

   /**
    * Get ISE Style of current active ISE. -- Not supported for now --
    * @param ctx context used to map real loaded APIs
    * @param style see ISE_STYLE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * THIS API IS NOT SUPPORTED NOW
    */
   EAPI void ecore_imf_context_ise_get_style        (Ecore_IMF_Context *ctx, ISE_STYLE *style);

   /**
    * Get ISE position of current active ISE. 
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param rect    
    *   int rect.x, top-left x co-ordinate of rectangle;
    *   int rect.y, top-left y co-ordinate of rectangle;
    *   int rect.width, width of rectangle ;
    *   int rect.height,  height of rectangle;
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     Ecore_IMF_Context *imf_context = NULL;
    *     ISE_RECT rect;   
    *     imf_context = ecore_get_imf_context();
    *     if (imf_context)
    *     {
    *         ecore_imf_context_ise_get_window_rect (imf_context, &rect);
    *   	  //here application can get window size rect 
    *		  printf ("rect.x=%d \n", rect.x);
    *		  printf ("rect.y=%d \n", rect.y);
    *		  printf ("rect.width=%d \n", rect.width);
    *		  printf ("rect.height=%d \n", rect.height);
    *     }
    *	  //do imf related things
    *  	  ecore_imf_shutdown();
    * 	  //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_window_rect  (Ecore_IMF_Context *ctx, ISE_RECT *rect);

   /**
    * Set ISE private key before show ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * Since the second parameter of this API requires a layout index, so before using this API application has to set a specific layout and that layout index 
    * should be passed in the 2nd argument of this API(see sample code).
    * @param ctx context used to map real loaded APIs
    * @param layout_index index of layout page to be set
    * @param key_index index of key to be set
    * @param label text label to be appeared on private key
    * @param value value of key, If NULL it will use original value of key
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_URL;
    *     
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_layout (imf_context, layout);
    *         ecore_imf_context_ise_set_private_key (imf_context, layout, 0, "www", "www");
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_private_key  (Ecore_IMF_Context *ctx, int layout_index, int key_index, const char* label, const char* value);

   /**
    * Set ISE private key by image before show ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * Since the second parameter of this API requires a layout index, so before using this API application has to set a specific layout and that layout index 
    * should be passed in the 2nd argument of this API(see sample code).
    * @param ctx context used to map real loaded APIs
    * @param layout_index index of layout page to be set
    * @param key_index index of key to be set
    * @param label image file path to be appeared on private key
    * @param value value of key, If NULL it will use original value of key
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_URL;
    *     
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_layout (imf_context, layout);
    *         ecore_imf_context_ise_set_private_key_by_image (imf_context, 1, 0, "/usr/share/themes/pixmap/IME/ime_3X4_www.ifg", "www");
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_private_key_by_image (Ecore_IMF_Context *ctx, int layout_index, int key_index, const char* img_path, const char* value);

   /**
    * Set ISE Layout before show ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * @param ctx context used to map real loaded APIs
    * @param layout see ISE_LAYOUT
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_EMAIL;
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_layout (imf_context, layout);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_layout  (Ecore_IMF_Context *ctx, ISE_LAYOUT layout);

   /**
    * Get ISE Layout of current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param layout see ISE_LAYOUT
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_EMAIL;
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_get_layout (imf_context, &layout); 
    *         //here u can see what the current layout is
    *         ecore_imf_context_ise_reset (imf_context);
    *         layout = ISE_LAYOUT_EMAIL;
    *         ecore_imf_context_ise_set_layout (imf_context, layout);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_layout  (Ecore_IMF_Context *ctx, ISE_LAYOUT  *layout);

   /**
    * Reset ISE Context including its Style. 
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * This is special function that should be called before calling any ecore_imf_context_set*** APIs to restore all default properties of ISE.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    *
    * NOTE: This API MUST be called before calling ecore_imf_context_ise_show().
    */
   EAPI void ecore_imf_context_ise_reset       (Ecore_IMF_Context *ctx);        /* Same as reset to default property*/

   /**
    * Set ISE screen orientation.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * To show the keypad in landscape mode applicaiton should first call this API with 2nd parameter as 90 or 270.
    * After then only application should call ecore_imf_context_ise_show() function.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *	  int degree = 90; // the degree value can be either 90/270 for landscape mode and normal portrait mode 0/360.
    *	  if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset(imf_context);
    *         ecore_imf_context_ise_set_screen_orientation(imf_context, degree);
    *         ecore_imf_context_ise_show(imf_context, obj, ISE_STATE_SHOW);
    *     }
    *     //do imf related things
    *     ecore_imf_shutdown();
    * }
    */
   EAPI void ecore_imf_context_ise_set_screen_orientation (Ecore_IMF_Context *ctx, int  orientation);

   /**
    * Get name of current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param name ISE name to be got
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     int len = 256;
    *     char *isename = (char*) malloc (len);
    *     memset(isename, '\0', sizeof(isename));
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_get_active_isename (imf_context, isename);
    *         printf("get isename=[%s]\n", isename);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_active_isename     (Ecore_IMF_Context *ctx, char* name);

   /**
    * Set ISE by its name.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * @param ctx context used to map real loaded APIs
    * @param name ISE name to be set
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context);
    *         ecore_imf_context_ise_set_active_ise_by_name (imf_context, "Input Pad");
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_set_active_ise_by_name (Ecore_IMF_Context *ctx, const char* name);

   /**
    * Set ISE by its uuid.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * @param ctx context used to map real loaded APIs
    * @param uuid ISE uuid to be set
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context);
    *         ecore_imf_context_ise_set_active_ise_by_uuid (imf_context, "ff110940-b8f0-4062-9ff6-a84f4f3575c0");
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_set_active_ise_by_uuid (Ecore_IMF_Context *ctx, const char* uuid);

   /**
    * Get list of ISEs.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param iselist pointer to the list to be got.
    * @return  int ise counter of iselist
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_EMAIL,
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         char** iselist;
    *         int count,i;
    *         count = ecore_imf_context_ise_get_iselist(imf_context, &iselist);
    *         printf("get_iselist : count[%d] ", count);
    *         for (i=0;i<count;i++)
    *             printf("[%d:%s] ", i, iselist[i]);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI int ecore_imf_context_ise_get_iselist (Ecore_IMF_Context *ctx, char*** iselist);

   /**
    * Get state of current active ISE.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs
    * @param state see ISE_STATE
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state;
    *
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_get_ise_state (imf_context, &state); 
    *         //here u can see what the current state is
    *         ecore_imf_context_ise_reset (imf_context);
    *         state = ISE_STATE_SHOW;
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */
   EAPI void ecore_imf_context_ise_get_ise_state          (Ecore_IMF_Context *ctx, ISE_STATE *state);

   /**
    * This API is depricated.
    * Application can register a callback function which will be called if there is change in ise state,language,mode etc. 
    * @param ctx context used to map real loaded APIs.
    * @param pListenerCallback the callback function to be called 
    * @param data application-ISE specific data.
    * @return an integer unique to callabck registered.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EINA_DEPRECATED EAPI int ecore_imf_context_ise_state_add_listener (Ecore_IMF_Context *ctx, void (*plistenerCallBackFunc) (ISE_EVENT,int), void *data);

   /**
    * This API is depricated.
    * To deregister(remove) the callback initially registered by application.  
    * param listener_id the unique number returned while registering the concerned callback.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EINA_DEPRECATED EAPI void ecore_imf_context_ise_state_remove_listener (Ecore_IMF_Context *ctx, int listener_id);

   /**
    * same as ecore_imf_context_ise_state_add_listener() wihout any application-ISE specific data.  -- Not supported for now --
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EINA_DEPRECATED EAPI int ecore_imf_context_ise_state_change_listener (Ecore_IMF_Context *ctx, void (*plistenerCallBackFunc) (ISE_EVENT, int));

   /**
    * Application can register a callback function which will be called if there is change in ise state,language,mode etc. 
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * @param ctx context used to map real loaded APIs.
    * @param pEventCallback the callback function to be called 
    * @param data application-ISE specific data.
    * @return an integer unique to callabck registered.
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * void _ise_event_callback(void *data, ISE_EVENT type, int value)
    * {
    *     Ecore_IMF_Context *ic = (Ecore_IMF_Context *)data;
    *
    *     switch(type){
    *         case ISE_STATE_EVENT:
    *         if(value == ISE_STATE_SHOW) {
    *         	// ISE state has changed to ISE_STATE_SHOW status
    *         }else if(value == ISE_STATE_HIDE) {
    *         	// ISE state has changed to ISE_STATE_HIDE status
    *         }
    *         break;
    *     }
    *     printf("type: %d, value: %d\n", type, value);
    * }
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    * 
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         //just one listener callback can be added for now
    *         ecore_imf_context_ise_event_callback_set (imf_context, _ise_event_callback, imf_context); 
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    * In order to deregister the callback function registered application should follow the below step.
    * ecore_imf_context_ise_event_callback_set (imf_context, NULL, NULL);
    */
   EAPI void ecore_imf_context_ise_event_callback_set (Ecore_IMF_Context *ctx, void (*pEventCallBackFunc) (void *,ISE_EVENT,int), void *data);
    
   /**
    * cowork with Mainwindow of elementary. -- Not supported for now --
    * @ingroup Ecore_IMF_Context_IMControl_Group
    */
   EAPI void ecore_imf_context_ise_initialize (Ecore_IMF_Context *ctx, Evas_Object * mainwindow);

   /**
    * Get the preedit string of the focused context.
    * @param ctx context used to map real loaded APIs
    * @return  const char * the preedit string of the focused context
    **/
   EAPI const char * ecore_imf_context_get_focused_preedit_string (Ecore_IMF_Context *ctx);

   /**
    * Set the key to be disabled.
    * To use this API applicaiton should include Ecore_IMF.h header file.
    * Before calling this API, every application should call ecore_imf_init() to initialize the ecore_imf shared library.
    * The first parameter i.e Ecore_IMF_Context *ctx is used to map the ecore_imf API into real implemented API which is inside ISF.
    * Before using any ecore_imf_context_set*** APIs the applciation must call ecore_imf_context_ise_reset() function.
    * Since the second parameter of this API requires a layout index, so before using this API application has to set a specific layout and that layout index 
    * should be passed in the 2nd argument of this API(see sample code).
    * @param ctx context used to map real loaded APIs
    * @param layout_index index of layout page to be set
    * @param key_index index of key to be set
    * @param disabled The state
    * @ingroup Ecore_IMF_Context_IMControl_Group
    * @code
    * #include <Ecore_IMF.h>
    *
    * static void entry_clicked_cb(void *data, Evas_Object *obj, void *event_info)
    * {
    *     ecore_imf_init();
    *     ISE_STATE state = ISE_STATE_SHOW;
    *     ISE_LAYOUT layout = ISE_LAYOUT_NUMBER;
    *     
    *     Ecore_IMF_Context *imf_context = NULL;
    *     imf_context = ecore_get_imf_context();
    *     
    *     if (imf_context)
    *     {    
    *         ecore_imf_context_ise_reset (imf_context); 
    *         ecore_imf_context_ise_set_layout (imf_context, layout);
    *         ecore_imf_context_ise_set_disable_key (imf_context, layout, ISE_KEY_SPACE, EINA_TRUE);
    *         ecore_imf_context_ise_show (imf_context, obj, state);
    *     }
    *
    *     //do imf related things
    * 
    *     ecore_imf_shutdown();
    * 
    *     //do imf irrelated things
    * }
    * @endcode
    */    
   EAPI void ecore_imf_context_ise_set_disable_key  (Ecore_IMF_Context *ctx, int layout_index, int key_index, Eina_Bool disabled);

   /* The following entry points must be exported by each input method module
    */

   /*
    * int                imf_module_init   (const Ecore_IMF_Context_Info **info);
    * void               imf_module_exit   (void);
    * Ecore_IMF_Context *imf_module_create (void);
    */

#ifdef __cplusplus
}
#endif

#endif
