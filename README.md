# CLI Parse

This is a small collection of utilities for parsing CLI arguments in the form:
`-flag:value` or `-flag`. I find this particular style of CLI flags to be
consistent and easy to parse visually and with software, but not many people
use it (most notable usage I know of is the Odin language compiler).

All functions follow the same structure of returning 2 lists, one containing
pairs the flags and their values (or an empty string/`true` for lonely/toggle flags)
and the other returns the non-flag arguments. Both lists are in the same order
as provided to the function

