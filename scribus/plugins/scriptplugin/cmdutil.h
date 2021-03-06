/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/
#ifndef CMDUTIL_H
#define CMDUTIL_H

// Pulls in <Python.h> first
#include "cmdvar.h"

double PointToValue(double Val);
double ValueToPoint(double Val);

/*! \brief Convert an X coordinate part in page units to a document coordinate in system units.
*/
double pageUnitXToDocX(double pageUnitX);
/// \brief Doc units -> page-relative units
double docUnitXToPageX(double pageUnitX);

/*! \brief Convert a Y coordinate part in page units to a document coordinate
in system units. The document coordinates have their origin somewhere
up and left of the first page, where page coordinates have their
origin on the top left of the current page. */
double pageUnitYToDocY(double pageUnitY);
/// \brief Doc units -> page-relative units
double docUnitYToPageY(double pageUnitY);

PageItem *GetItem(const QString& name);
void ReplaceColor(const QString& col, const QString& rep);

/*!
 * @brief Returns named PageItem, or selection if name '', or exception and NULL if no item.
 *
 * Returns a pointer to a PageItem by looking it up by name - page independent.
 * If `name' is empty, returns selected item.  If the named item is not found,
 * or `name' is empty and no item is selected, sets an exception and returns
 * NULL.
 *
 * @author 03/10/2004 petr vanek
 * @author 05/02/02 Craig Ringer
 */
PageItem* GetUniqueItem(const QString& name);

/*!
 * @brief Returns named PageItem, or exception and NULL if not found.
 *
 * @author 03/10/2004 Petr Vanek
 * @author 05/02/02 Craig Ringer
 */
PageItem* getPageItemByName(const QString& name);

// 2004-10-27 Craig Ringer see cmdutil.cpp for description
bool checkHaveDocument();

/*!
 * @brief Returns true if the page number is between 0 and the number of pages.
 *
 * If the page number is smaller than 0 or bigger than the number of pages
 * a Python exception is set, before returning false.
 *
 * The caller is required to check the returned value and return nullptr on false.
 *
 * @author ale rimoldi
 */
bool checkValidPageNumber(int page);

// 2004-11-12 Craig Ringer see cmdutil.cpp for description
bool ItemExists(const QString& name);

/*!
 * @brief Returns a list of the names of all selected PageItems
 */
QStringList getSelectedItemsByName();

/*!
 * @brief Replaces the current selection by selecting all the items named in the passed QStringList
 *
 * Returns false if one or more items can't be selected, true if all were selected.
 * Selection state is undefined on failure.
 */
bool setSelectedItemsByName(const QStringList& itemNames);

/*!
 * @brief Helper method to parse a border from a list of tuples.
 */
TableBorder parseBorder(PyObject* borderLines, bool* ok);

/*!
 * @brief Helper method to convert a PyUnicode object to a QString
 */
QString PyUnicode_asQString(PyObject* arg);

#endif
