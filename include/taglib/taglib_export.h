/***************************************************************************
    copyright            : (C) 2002 - 2008 by Scott Wheeler
    email                : wheeler@kde.org
 ***************************************************************************/

/***************************************************************************
 *   This library is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU Lesser General Public License version   *
 *   2.1 as published by the Free Software Foundation.                     *
 *                                                                         *
 *   This library is distributed in the hope that it will be useful, but   *
 *   WITHOUT ANY WARRANTY; without even the implied warranty of            *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU     *
 *   Lesser General Public License for more details.                       *
 *                                                                         *
 *   You should have received a copy of the GNU Lesser General Public      *
 *   License along with this library; if not, write to the Free Software   *
 *   Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA         *
 *   02110-1301  USA                                                       *
 *                                                                         *
 *   Alternatively, this file is available under the Mozilla Public        *
 *   License Version 1.1.  You may obtain a copy of the License at         *
 *   http://www.mozilla.org/MPL/                                           *
 ***************************************************************************/

#ifndef TAGLIB_EXPORT_H
#define TAGLIB_EXPORT_H

#if 1
#define TAGLIB_EXPORT
#elif (defined(_WIN32) || defined(_WIN64))
#ifdef MAKE_TAGLIB_LIB
#define TAGLIB_EXPORT __declspec(dllexport)
#else
#define TAGLIB_EXPORT __declspec(dllimport)
#endif
#elif defined(__GNUC__) && (__GNUC__ > 4 || __GNUC__ == 4 && __GNUC_MINOR__ >= 1)
#define TAGLIB_EXPORT __attribute__ ((visibility("default")))
#else
#define TAGLIB_EXPORT
#endif

#if defined _MSC_VER && !defined TAGLIB_STATIC
/*!
 * Suppress MSVC C4251 warning for next statement.
 * Unfortunately, MSVC exports everything (not only public members) when
 * __declspec(dllexport) is set at the class level via TAGLIB_EXPORT, which
 * leads to many "needs to have dll-interface to be used by clients" C4251
 * warnings issued by MSVC, because the std::unique_ptr pimpls are
 * exported too. This macro can be used before private STL fields to suppress
 * such warnings.
*/
#define TAGLIB_MSVC_SUPPRESS_WARNING_NEEDS_TO_HAVE_DLL_INTERFACE _Pragma("warning(suppress: 4251)")
#else
#define TAGLIB_MSVC_SUPPRESS_WARNING_NEEDS_TO_HAVE_DLL_INTERFACE
#endif

#endif
