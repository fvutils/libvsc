
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
 * RNG.cpp
 *
 *  Created on: Jul 5, 2020
 *      Author: ballance
 */

#include "RNG.h"

namespace vsc {

RNG::RNG(uint32_t seed) {
	m_a = 0x5DEECE66DULL;
	m_c = 0xb;

	m_next = (0x330EULL << 32)
			| ((uint64_t)(seed & 0xFFFF) << 16)
			| (seed >> 16);
	/*
	m_next[0] = (seed >> 16);
	m_next[1] = (seed & 0xFFFF);
	m_next[2] = 0x330E;
	 */
}

RNG::~RNG() {
	// TODO Auto-generated destructor stub
}

uint32_t RNG::next() {
	uint64_t		X;
	uint64_t		tmp;

//	X = (((uint64_t)m_next[2] << 32) | ((uint32_t)m_next[1] << 16) | m_next[0]);
	m_next = ((m_next * m_a + m_c) & 0xFFFFFFFFFFFF);

	return (m_next >> 16);
}

} /* namespace vsc */
