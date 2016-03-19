// Copyright (c) 2006, 2007 Julio M. Merino Vidal
// Copyright (c) 2008 Ilya Sokolov, Boris Schaeling
// Copyright (c) 2009 Boris Schaeling
// Copyright (c) 2010 Felipe Tanus, Boris Schaeling
// Copyright (c) 2011, 2012 Jeff Flinn, Boris Schaeling
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PROCESS_WINDOWS_INITIALIZERS_CLOSE_STDIN_HPP
#define BOOST_PROCESS_WINDOWS_INITIALIZERS_CLOSE_STDIN_HPP

#include <boost/detail/winapi/process.hpp>
#include <boost/detail/winapi/handles.hpp>
#include <boost/process/detail/initializers/handler_base.hpp>

namespace boost { namespace process { namespace windows { namespace initializers {

struct close_stdin : public ::boost::process::detail::initializers::handler_base
{
public:
    template <class WindowsExecutor>
    void on_setup(WindowsExecutor &e) const
    {
        e.startup_info.hStdInput = boost::detail::winapi::INVALID_HANDLE_VALUE_;
        e.startup_info.dwFlags  |= boost::detail::winapi::STARTF_USESTDHANDLES_;
    }
};

}}}}

#endif