/*
For general Scribus (>=1.3.2) copyright and licensing information please refer
to the COPYING file provided with the program. Following this notice may exist
a copyright and/or license notice that predates the release of Scribus 1.3.2
for which a new license (GPL+exception) is in place.
*/

#ifndef SHORTCUTWIDGET_H
#define SHORTCUTWIDGET_H

#include <QWidget>

class QEvent;

#include "ui_shortcutwidget.h"

// class Keys;


//! \brief User defined key-shortcuts for Style Manager dialog.
class ShortcutWidget : public QWidget, public Ui::ShortcutWidget
{
	Q_OBJECT

public:
	ShortcutWidget(QWidget* parent = nullptr);
	~ShortcutWidget();

	void setShortcut(const QString &shortcut);
	void setAllowedModifiers(int allowed, int required);
	static QString getKeyText(int KeyC);
	void languageChange();

public slots:
	void setKeyText();
	void setNoKey();

protected:
	int keyCode;
	QString Part0;
	QString Part1;
	QString Part2;
	QString Part3;
	QString Part4;
	int requiredModifiers;
	int allowedModifiers;

	void changeEvent(QEvent *e) override;
	
	bool event(QEvent* ev) override;
	void keyPressEvent(QKeyEvent *k) override;
	void keyReleaseEvent(QKeyEvent *k) override;

signals:
	/**
	 * @brief emitted when a shrotcut is changed.
	 *
	 * Parameter will be QString() when No key is used
	 */
	void newKey(const QString&);
};

#endif
