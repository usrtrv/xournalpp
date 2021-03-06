/*
 * Xournal++
 *
 * Dialog to select a Image (to insert as background)
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "gui/GladeGui.h"
#include <XournalType.h>

#include <vector>

class BackgroundImage;
class Document;
class ImageView;
class Settings;
class BackgroundImage;

typedef std::vector<ImageView*> ImageViewVector;

class ImagesDialog : public GladeGui
{
public:
	ImagesDialog(GladeSearchpath* gladeSearchPath, Document* doc, Settings* settings);
	virtual ~ImagesDialog();

public:
	virtual void show(GtkWindow* parent);

	void setBackgroundWhite();

	void setSelected(size_t selected);

	BackgroundImage getSelectedImage();
	bool shouldShowFilechooser();

	Settings* getSettings();
private:
	void layout();
	void updateOkButton();

	static void sizeAllocate(GtkWidget* widget, GtkRequisition* requisition, ImagesDialog* dlg);
	static void okButtonCallback(GtkButton* button, ImagesDialog* dlg);
	static void filechooserButtonCallback(GtkButton* button, ImagesDialog* dlg);

private:
	XOJ_TYPE_ATTRIB;

	bool backgroundInitialized;

	Settings* settings;

	size_t selected;
	int lastWidth;

	int selectedPage;

	ImageViewVector images;

	GtkWidget* scrollPreview;
	GtkWidget* widget;
};
