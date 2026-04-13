project('UnoHttpBridge', 'cpp',
        version : '1.0.0',
        default_options : ['warning_level=3', 'cpp_std=c++20'])

# Добавляем флаги компиляции (C++-флаги)
add_project_arguments('-DCROW_ENABLE_DEBUG', language : 'cpp')

# Указываем зависимости (библиотеки)
boost_dep = dependency('boost', modules : ['system'])
pthread_dep = dependency('threads')

# Собираем исполняемый файл с нужными зависимостями и флагами
UnoHttpBridge = executable('UnoHttpBridge',
                           'main.cpp',
                           install : true,
                           dependencies : [boost_dep, pthread_dep])

# Добавляем отладочную информацию (аналог -ggdb)
# В Meson это обычно включается по умолчанию в debug-режиме,
# но можно явно указать, если требуется.

# Тесты
test('test', UnoHttpBridge)