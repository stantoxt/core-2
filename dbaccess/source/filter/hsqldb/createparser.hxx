/* -*- Mode: C++; tab-width: 4; indent-tabs-mode: nil; c-basic-offset: 4 -*- */
/*
 * This file is part of the LibreOffice project.
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/.
 */

#ifndef INCLUDED_DBACCESS_SOURCE_FILTER_HSQLDB_CREATEPARSER_HXX
#define INCLUDED_DBACCESS_SOURCE_FILTER_HSQLDB_CREATEPARSER_HXX

#include <vector>
#include "columndef.hxx"

namespace dbahsql
{
class SAL_DLLPUBLIC_EXPORT CreateStmtParser
{
private:
    std::vector<ColumnDefinition> m_aColumns;
    std::vector<OUString> m_aForeignParts;
    OUString m_sTableName;

protected:
    void parseColumnPart(const OUString& sColumnPart);

public:
    CreateStmtParser();
    virtual ~CreateStmtParser() {}

    /**
     * @return name of the table which is to be created.
     */
    OUString getTableName() const { return m_sTableName; }

    /**
     * @return a vector of column descriptors, representing the columns of the
     * parsed statement.
     */
    const std::vector<ColumnDefinition>& getColumnDef() const { return m_aColumns; }

    /**
     * @return a vector of words.
     */
    const std::vector<OUString>& getForeignParts() const { return m_aForeignParts; }

    /**
     * Parses a create statement.
     *
     * @param SQL "CREATE" statement
     */
    void parse(const OUString& sSql);

    /**
     * Recreate the sql statement.
     */
    virtual OUString compose() const = 0;
};
}

#endif // INCLUDED_DBACCESS_SOURCE_FILTER_HSQLDB_CREATEPARSER_HXX

/* vim:set shiftwidth=4 softtabstop=4 expandtab: */
