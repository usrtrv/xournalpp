/*
 * Xournal++
 *
 * Toolbar edit dialog
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */

#ifndef __TOOLBARCUSTOMIZEDIALOG_H__
#define __TOOLBARCUSTOMIZEDIALOG_H__

#include "../GladeGui.h"
#include "../../util/XournalType.h"

class MainWindow;
class AbstractToolItem;

class ToolbarCustomizeDialog : public GladeGui {
public:
	ToolbarCustomizeDialog(GladeSearchpath * gladeSearchPath, MainWindow * win);
	virtual ~ToolbarCustomizeDialog();

public:
	virtual void show();

private:
	XOJ_TYPE_ATTRIB;

	MainWindow * win;
};

#endif /* __TOOLBARCUSTOMIZEDIALOG_H__ */