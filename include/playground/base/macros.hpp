#pragma once

#define PG_RETURN_IF(v) if((v)) return;
#define PG_RETURN_VALUE_IF(v, val) if((v)) return (val);