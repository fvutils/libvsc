
/**
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */

/*
 * IVisitor.h
 *
 *  Created on: Jul 3, 2020
 *      Author: ballance
 */

#pragma once

namespace vsc {

class ConstraintBlock;
class ConstraintIf;
class ConstraintScope;
class ConstraintSoft;
class ConstraintStmt;
class ConstraintExpr;

class ExprBin;
class ExprCond;
class ExprDynamicConstraintRef;
class ExprFieldRef;
class ExprListSubscript;
class ExprRange;
class ExprRangelist;
class ExprUnary;
class ExprValLiteral;

class ExprValEnum;
class ExprValNumeric;

class FieldComposite;
class FieldScalar;

class IVisitor {
public:

	virtual ~IVisitor() { }

	virtual void visitConstraintBlock(ConstraintBlock *c) = 0;

	virtual void visitConstraintIf(ConstraintIf *c) = 0;

	virtual void visitConstraintScope(ConstraintScope *c) = 0;

	virtual void visitConstraintSoft(ConstraintSoft *c) = 0;

	virtual void visitConstraintStmtEnter(ConstraintStmt *c) = 0;

	virtual void visitConstraintStmtLeave(ConstraintStmt *c) = 0;

	virtual void visitConstraintExpr(ConstraintExpr *c) = 0;

	virtual void visitExprBin(ExprBin *e) = 0;

	virtual void visitExprCond(ExprCond *e) = 0;

	virtual void visitExprDynamicConstraintRef(ExprDynamicConstraintRef *e) = 0;

	virtual void visitExprFieldRef(ExprFieldRef *e) = 0;

	virtual void visitExprListSubscript(ExprListSubscript *e) = 0;

	virtual void visitExprRange(ExprRange *e) = 0;

	virtual void visitExprRangelist(ExprRangelist *e) = 0;

	virtual void visitExprUnary(ExprUnary *e) = 0;

	virtual void visitExprValLiteral(ExprValLiteral *e) = 0;

	virtual void visitExprValEnum(ExprValEnum *e) = 0;

	virtual void visitExprValNumeric(ExprValNumeric *e) = 0;

	virtual void visitFieldComposite(FieldComposite *f) = 0;

	virtual void visitFieldScalar(FieldScalar *f) = 0;

};

}


