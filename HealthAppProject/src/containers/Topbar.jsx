import React, { createElement } from 'react'
import Icon from '@mdi/react'
import {
  mdiLightbulb,
  mdiLightbulbOutline
} from '@mdi/js'

import { H2, H6, Card, IconButton, ToggleButton } from 'ui-neumorphism'



class Topbar extends React.Component {
  // open(url) {
  //   window.open(url, '_blank')
  // }

  render() {
    const { dark, onClick, onMenuClick, size } = this.props
    return (
      <Card flat dark={dark} className={`main-topbar`}>
        <Card flat className='d-flex align-center topbar-headline'>
        </Card>
        <Card flat className='d-flex align-center topbar-actions'>
          <ToggleButton className='topbar-action' onChange={onClick}>
            <Icon path={dark ? mdiLightbulbOutline : mdiLightbulb} size={1} />
          </ToggleButton>
        </Card>
      </Card>
    )
  }
}

export default Topbar
