#include <string.h>

#include "ecore_xcb_private.h"

/**
 * @defgroup Ecore_X_Atom_Group XCB Atom Functions
 *
 * Functions that operate on atoms.
 */

/*********/
/* Atoms */
/*********/

#include "ecore_x_atoms_decl.h"

/* To avoid round trips, the initialization is separated in 2
   functions: _ecore_xcb_atom_init and
   _ecore_xcb_atom_init_finalize. The first one gets the cookies and
   the second one gets the replies and set the atoms. */

#define FETCH_ATOM(s)\
   atom_cookies[i] = xcb_intern_atom(_ecore_xcb_conn, 0, strlen(s), s);\
   i++

#define FETCH_ATOM_FINALIZE(x)\
   reply = xcb_intern_atom_reply(_ecore_xcb_conn, atom_cookies[i], NULL);\
   x = reply->atom;\
   free(reply);\
   i++;

void
_ecore_x_atom_init(xcb_intern_atom_cookie_t *atom_cookies)
{
   int i = 0;

   /* generic atoms */
   FETCH_ATOM("COMPOUND_TEXT");
   FETCH_ATOM("FILE_NAME");
   FETCH_ATOM("TEXT");
   FETCH_ATOM("UTF8_STRING");

   /* dnd atoms */
   FETCH_ATOM("JXSelectionWindowProperty");
   FETCH_ATOM("XdndSelection");
   FETCH_ATOM("XdndAware");
   FETCH_ATOM("XdndEnter");
   FETCH_ATOM("XdndTypeList");
   FETCH_ATOM("XdndPosition");
   FETCH_ATOM("XdndActionCopy");
   FETCH_ATOM("XdndActionMove");
   FETCH_ATOM("XdndActionPrivate");
   FETCH_ATOM("XdndActionAsk");
   FETCH_ATOM("XdndActionList");
   FETCH_ATOM("XdndActionLink");
   FETCH_ATOM("XdndActionDescription");
   FETCH_ATOM("XdndProxy");
   FETCH_ATOM("XdndStatus");
   FETCH_ATOM("XdndLeave");
   FETCH_ATOM("XdndDrop");
   FETCH_ATOM("XdndFinished");

   /* old E atom */
   FETCH_ATOM("_E_FRAME_SIZE");

   /* old Gnome atom */
   FETCH_ATOM("_WIN_LAYER");

   /* ICCCM */
   FETCH_ATOM("WM_PROTOCOLS");
   FETCH_ATOM("WM_COLORMAP_WINDOWS");

   FETCH_ATOM("WM_STATE");

   FETCH_ATOM("WM_CHANGE_STATE");

   FETCH_ATOM("WM_TAKE_FOCUS");
   FETCH_ATOM("WM_SAVE_YOURSELF");
   FETCH_ATOM("WM_DELETE_WINDOW");

   FETCH_ATOM("WM_COLORMAP_NOTIFY");

   FETCH_ATOM("SM_CLIENT_ID");
   FETCH_ATOM("WM_CLIENT_LEADER");
   FETCH_ATOM("WM_WINDOW_ROLE");

   /* Motif WM atom */
   FETCH_ATOM("_MOTIF_WM_HINTS");

   /* NetWM atoms */
   FETCH_ATOM("_NET_SUPPORTED");
   FETCH_ATOM("_NET_CLIENT_LIST");
   FETCH_ATOM("_NET_CLIENT_LIST_STACKING");
   FETCH_ATOM("_NET_NUMBER_OF_DESKTOPS");
   FETCH_ATOM("_NET_DESKTOP_GEOMETRY");
   FETCH_ATOM("_NET_DESKTOP_VIEWPORT");
   FETCH_ATOM("_NET_CURRENT_DESKTOP");
   FETCH_ATOM("_NET_DESKTOP_NAMES");
   FETCH_ATOM("_NET_ACTIVE_WINDOW");
   FETCH_ATOM("_NET_WORKAREA");
   FETCH_ATOM("_NET_SUPPORTING_WM_CHECK");
   FETCH_ATOM("_NET_VIRTUAL_ROOTS");
   FETCH_ATOM("_NET_DESKTOP_LAYOUT");
   FETCH_ATOM("_NET_SHOWING_DESKTOP");

   FETCH_ATOM("_NET_CLOSE_WINDOW");
   FETCH_ATOM("_NET_MOVERESIZE_WINDOW");
   FETCH_ATOM("_NET_WM_MOVERESIZE");
   FETCH_ATOM("_NET_RESTACK_WINDOW");
   FETCH_ATOM("_NET_REQUEST_FRAME_EXTENTS");

   FETCH_ATOM("_NET_WM_NAME");
   FETCH_ATOM("_NET_WM_VISIBLE_NAME");
   FETCH_ATOM("_NET_WM_ICON_NAME");
   FETCH_ATOM("_NET_WM_VISIBLE_ICON_NAME");
   FETCH_ATOM("_NET_WM_DESKTOP");

   FETCH_ATOM("_NET_WM_WINDOW_TYPE");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_DESKTOP");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_DOCK");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_TOOLBAR");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_MENU");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_UTILITY");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_SPLASH");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_DIALOG");
   FETCH_ATOM("_NET_WM_WINDOW_TYPE_NORMAL");

   FETCH_ATOM("_NET_WM_STATE");
   FETCH_ATOM("_NET_WM_STATE_MODAL");
   FETCH_ATOM("_NET_WM_STATE_STICKY");
   FETCH_ATOM("_NET_WM_STATE_MAXIMIZED_VERT");
   FETCH_ATOM("_NET_WM_STATE_MAXIMIZED_HORZ");
   FETCH_ATOM("_NET_WM_STATE_SHADED");
   FETCH_ATOM("_NET_WM_STATE_SKIP_TASKBAR");
   FETCH_ATOM("_NET_WM_STATE_SKIP_PAGER");
   FETCH_ATOM("_NET_WM_STATE_HIDDEN");
   FETCH_ATOM("_NET_WM_STATE_FULLSCREEN");
   FETCH_ATOM("_NET_WM_STATE_ABOVE");
   FETCH_ATOM("_NET_WM_STATE_BELOW");
   FETCH_ATOM("_NET_WM_STATE_DEMANDS_ATTENTION");

   FETCH_ATOM("_NET_WM_ALLOWED_ACTIONS");
   FETCH_ATOM("_NET_WM_ACTION_MOVE");
   FETCH_ATOM("_NET_WM_ACTION_RESIZE");
   FETCH_ATOM("_NET_WM_ACTION_MINIMIZE");
   FETCH_ATOM("_NET_WM_ACTION_SHADE");
   FETCH_ATOM("_NET_WM_ACTION_STICK");
   FETCH_ATOM("_NET_WM_ACTION_MAXIMIZE_HORZ");
   FETCH_ATOM("_NET_WM_ACTION_MAXIMIZE_VERT");
   FETCH_ATOM("_NET_WM_ACTION_FULLSCREEN");
   FETCH_ATOM("_NET_WM_ACTION_CHANGE_DESKTOP");
   FETCH_ATOM("_NET_WM_ACTION_CLOSE");
   FETCH_ATOM("_NET_WM_ACTION_ABOVE");
   FETCH_ATOM("_NET_WM_ACTION_BELOW");

   FETCH_ATOM("_NET_WM_STRUT");
   FETCH_ATOM("_NET_WM_STRUT_PARTIAL");
   FETCH_ATOM("_NET_WM_ICON_GEOMETRY");
   FETCH_ATOM("_NET_WM_ICON");
   FETCH_ATOM("_NET_WM_PID");
   FETCH_ATOM("_NET_WM_HANDLED_ICONS");
   FETCH_ATOM("_NET_WM_USER_TIME");
   FETCH_ATOM("_NET_STARTUP_ID");
   FETCH_ATOM("_NET_FRAME_EXTENTS");

   FETCH_ATOM("_NET_WM_PING");
   FETCH_ATOM("_NET_WM_SYNC_REQUEST");
   FETCH_ATOM("_NET_WM_SYNC_REQUEST_COUNTER");

   FETCH_ATOM("_NET_WM_WINDOW_OPACITY");
   FETCH_ATOM("_NET_WM_WINDOW_SHADOW");
   FETCH_ATOM("_NET_WM_WINDOW_SHADE");

   FETCH_ATOM("_NET_STARTUP_INFO_BEGIN");
   FETCH_ATOM("_NET_STARTUP_INFO");

   /* selection atoms */
   FETCH_ATOM("TARGETS");
   FETCH_ATOM("CLIPBOARD");
   FETCH_ATOM("_ECORE_SELECTION_PRIMARY");
   FETCH_ATOM("_ECORE_SELECTION_SECONDARY");
   FETCH_ATOM("_ECORE_SELECTION_CLIPBOARD");

   /* These atoms are already internally defined */
   ECORE_X_ATOM_SELECTION_PRIMARY = 1;
   ECORE_X_ATOM_SELECTION_SECONDARY = 2;
   ECORE_X_ATOM_ATOM = 4;
   ECORE_X_ATOM_CARDINAL = 6;
   ECORE_X_ATOM_STRING = 31;
   ECORE_X_ATOM_WINDOW = 33;
   ECORE_X_ATOM_WM_NAME = 39;
   ECORE_X_ATOM_WM_ICON_NAME = 37;
   ECORE_X_ATOM_WM_NORMAL_HINTS = 40;
   ECORE_X_ATOM_WM_SIZE_HINTS = 41;
   ECORE_X_ATOM_WM_HINTS = 35;
   ECORE_X_ATOM_WM_CLASS = 67;
   ECORE_X_ATOM_WM_TRANSIENT_FOR = 68;
   ECORE_X_ATOM_WM_COMMAND = 34;
   ECORE_X_ATOM_WM_CLIENT_MACHINE = 36;
   ECORE_X_ATOM_WM_ICON_SIZE = 38;

   /* Initialize the globally defined xdnd atoms */
   ECORE_X_DND_ACTION_COPY = ECORE_X_ATOM_XDND_ACTION_COPY;
   ECORE_X_DND_ACTION_MOVE = ECORE_X_ATOM_XDND_ACTION_MOVE;
   ECORE_X_DND_ACTION_LINK = ECORE_X_ATOM_XDND_ACTION_LINK;
   ECORE_X_DND_ACTION_ASK = ECORE_X_ATOM_XDND_ACTION_ASK;
   ECORE_X_DND_ACTION_PRIVATE = ECORE_X_ATOM_XDND_ACTION_PRIVATE;
} /* _ecore_x_atom_init */

void
_ecore_x_atom_init_finalize(xcb_intern_atom_cookie_t *atom_cookies)
{
   xcb_intern_atom_reply_t *reply = NULL;
   int i = 0;

   /* generic atoms */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_COMPOUND_TEXT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_FILE_NAME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_TEXT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_UTF8_STRING);

   /* dnd atoms */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_PROP_XDND);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_XDND);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_AWARE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ENTER);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_TYPE_LIST);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_POSITION);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_COPY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_MOVE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_PRIVATE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_ASK);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_LIST);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_LINK);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_ACTION_DESCRIPTION);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_PROXY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_STATUS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_LEAVE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_DROP);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_XDND_FINISHED);

   /* old E atom */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_E_FRAME_SIZE);

   /* old Gnome atom */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WIN_LAYER);

   /* ICCCM */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_PROTOCOLS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_COLORMAP_WINDOWS);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_STATE);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_CHANGE_STATE);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_TAKE_FOCUS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_SAVE_YOURSELF);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_DELETE_WINDOW);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_COLORMAP_NOTIFY);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SM_CLIENT_ID);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_CLIENT_LEADER);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_WM_WINDOW_ROLE);

   /* Motif WM atom */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_MOTIF_WM_HINTS);

   /* NetWM atoms */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_SUPPORTED);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_CLIENT_LIST);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_CLIENT_LIST_STACKING);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_NUMBER_OF_DESKTOPS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_DESKTOP_GEOMETRY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_DESKTOP_VIEWPORT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_CURRENT_DESKTOP);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_DESKTOP_NAMES);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_ACTIVE_WINDOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WORKAREA);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_SUPPORTING_WM_CHECK);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_VIRTUAL_ROOTS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_DESKTOP_LAYOUT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_SHOWING_DESKTOP);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_CLOSE_WINDOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_MOVERESIZE_WINDOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_MOVERESIZE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_RESTACK_WINDOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_REQUEST_FRAME_EXTENTS);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_NAME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_VISIBLE_NAME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ICON_NAME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_VISIBLE_ICON_NAME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_DESKTOP);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_DESKTOP);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_DOCK);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_TOOLBAR);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_MENU);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_UTILITY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_SPLASH);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_DIALOG);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_TYPE_NORMAL);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_MODAL);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_STICKY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_MAXIMIZED_VERT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_MAXIMIZED_HORZ);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_SHADED);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_SKIP_TASKBAR);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_SKIP_PAGER);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_HIDDEN);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_FULLSCREEN);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_ABOVE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_BELOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STATE_DEMANDS_ATTENTION);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ALLOWED_ACTIONS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_MOVE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_RESIZE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_MINIMIZE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_SHADE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_STICK);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_MAXIMIZE_HORZ);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_MAXIMIZE_VERT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_FULLSCREEN);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_CHANGE_DESKTOP);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_CLOSE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_ABOVE);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ACTION_BELOW);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STRUT);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_STRUT_PARTIAL);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ICON_GEOMETRY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_ICON);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_PID);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_HANDLED_ICONS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_USER_TIME);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_STARTUP_ID);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_FRAME_EXTENTS);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_PING);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_SYNC_REQUEST);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_SYNC_REQUEST_COUNTER);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_OPACITY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_SHADOW);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_WM_WINDOW_SHADE);

   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_STARTUP_INFO_BEGIN);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_NET_STARTUP_INFO);

   /* selection atoms */
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_TARGETS);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_CLIPBOARD);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_PROP_PRIMARY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_PROP_SECONDARY);
   FETCH_ATOM_FINALIZE(ECORE_X_ATOM_SELECTION_PROP_CLIPBOARD);
} /* _ecore_x_atom_init_finalize */

/**
 * Sends the InternAtom request.
 * @param name Name of the requested atom.
 * @ingroup Ecore_X_Atom_Group
 */
EAPI void
ecore_x_atom_get_prefetch(const char *name)
{
   xcb_intern_atom_cookie_t cookie;

   cookie = xcb_intern_atom_unchecked(_ecore_xcb_conn, 0, strlen(name), name);
   _ecore_xcb_cookie_cache(cookie.sequence);
} /* ecore_x_atom_get_prefetch */

/**
 * Gets the reply of the InternAtom request sent by ecore_x_atom_get_prefetch().
 * @ingroup Ecore_X_Atom_Group
 */
EAPI void
ecore_x_atom_get_fetch(void)
{
   xcb_intern_atom_cookie_t cookie;
   xcb_intern_atom_reply_t *reply;

   cookie.sequence = _ecore_xcb_cookie_get();
   reply = xcb_intern_atom_reply(_ecore_xcb_conn, cookie, NULL);
   _ecore_xcb_reply_cache(reply);
} /* ecore_x_atom_get_fetch */

/**
 * Retrieves the atom value associated to a name.
 * @param  name Unused.
 * @return      Associated atom value.
 *
 * Retrieves the atom value associated to a name. The reply is the
 * returned value of the function ecore_xcb_intern_atom_reply(). If
 * @p reply is @c NULL, the NULL atom is returned. Otherwise, the atom
 * associated to the name is returned.
 *
 * To use this function, you must call before, and in order,
 * ecore_x_atom_get_prefetch(), which sends the InternAtom request,
 * then ecore_x_atom_get_fetch(), which gets the reply.
 * @ingroup Ecore_X_Atom_Group
 */
EAPI Ecore_X_Atom
ecore_x_atom_get(const char *name __UNUSED__)
{
   xcb_intern_atom_reply_t *reply;

   reply = _ecore_xcb_reply_get();
   if (!reply)
      return XCB_NONE;

   return reply->atom;
} /* ecore_x_atom_get */

/**
 * Sends the GetAtomName request.
 * @param atom Atom to get the name from.
 * @ingroup Ecore_X_Atom_Group
 */
EAPI void
ecore_x_get_atom_name_prefetch(Ecore_X_Atom atom)
{
   xcb_get_atom_name_cookie_t cookie;

   cookie = xcb_get_atom_name_unchecked(_ecore_xcb_conn, atom);
   _ecore_xcb_cookie_cache(cookie.sequence);
} /* ecore_x_get_atom_name_prefetch */

/**
 * Gets the reply of the GetAtomName request sent by ecore_x_get_atom_name_prefetch().
 * @ingroup Ecore_X_Atom_Group
 */
EAPI void
ecore_x_get_atom_name_fetch(void)
{
   xcb_get_atom_name_cookie_t cookie;
   xcb_get_atom_name_reply_t *reply;

   cookie.sequence = _ecore_xcb_cookie_get();
   reply = xcb_get_atom_name_reply(_ecore_xcb_conn, cookie, NULL);
   _ecore_xcb_reply_cache(reply);
} /* ecore_x_get_atom_name_fetch */

/**
 * Retrieves the name of the given atom.
 * @param  atom Unused.
 * @return      The name of the atom.
 *
 * To use this function, you must call before, and in order,
 * ecore_x_get_atom_name_prefetch(), which sends the GetAtomName request,
 * then ecore_x_get_atom_name_fetch(), which gets the reply.
 * @ingroup Ecore_X_Atom_Group
 */
EAPI char *
ecore_x_atom_name_get(Ecore_X_Atom atom)
{
   xcb_get_atom_name_reply_t *reply;
   char *name;
   int length;

   reply = _ecore_xcb_reply_get();
   if (!reply)
      return NULL;

   length = xcb_get_atom_name_name_length(reply);
   name = (char *)malloc(sizeof(char) * (length + 1));
   if (!name)
      return NULL;

   memcpy(name, xcb_get_atom_name_name(reply), length);
   name[length] = '\0';

   return name;
} /* ecore_x_atom_name_get */

