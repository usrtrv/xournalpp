/*
 * Xournal++
 *
 * Handles PDF Export
 *
 * @author Xournal++ Team
 * https://github.com/xournalpp/xournalpp
 *
 * @license GNU GPLv2 or later
 */

#pragma once

#include "poppler/XojPopplerDocument.h"
#include <poppler/Object.h>

enum PdfRefEntryType
{
	PDF_REF_ENTRY_TYPE_REF,
	PDF_REF_ENTRY_TYPE_DICT
};

class PdfRefEntry
{
public:
	PdfRefEntry(PdfRefEntryType type, int objectId, Object* object, int refSourceId, Ref ref, XojPopplerDocument doc);
	virtual ~PdfRefEntry();

public:
	bool equalsRef(const Ref& ref);

public:
	XOJ_TYPE_ATTRIB;

	PdfRefEntryType type;
	int objectId;
	int refSourceId;
	XojPopplerDocument doc;
	Object* object;
	Ref ref;

public:
	/**
	 * Mark this reference as used
	 */
	void markAsUsed();

	bool isUsed();
private:
	bool used;
};
