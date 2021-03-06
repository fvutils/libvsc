
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
 * ExprCond.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: ballance
 */

#include "ExprCond.h"

namespace vsc {

ExprCond::ExprCond(
		Expr		*cond,
		Expr		*true_e,
		Expr		*false_e) : m_cond(cond),
				m_true_e(true_e), m_false_e(false_e) {
}

ExprCond::ExprCond(
		ExprSP		cond,
		ExprSP		true_e,
		ExprSP		false_e) : m_cond(cond),
				m_true_e(true_e), m_false_e(false_e) {
}

ExprCond::~ExprCond() {
	// TODO Auto-generated destructor stub
}

} /* namespace vsc */
