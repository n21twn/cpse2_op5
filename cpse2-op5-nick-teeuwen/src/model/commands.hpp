#pragma once
// Verzamel-header: bundelt alle command-klassen zodat andere bestanden
// (bijv. de controllers) maar één include nodig hebben in plaats van losse
// includes per command-type.
#include "command.hpp"
#include "moveCommand.hpp"
#include "undoCommand.hpp"
#include "restartCommand.hpp"