import React, { createElement } from 'react'
import ReactDOM from 'react-dom'
import {Link} from "react-router-dom"

import Icon from '@mdi/react'
import {
  mdiRun,
  mdiYoga,
  mdiPlus,
  mdiHome,
  mdiBell,
  mdiTicket,
  mdiAccount,
  mdiArmFlex,
  mdiDumbbell,
  mdiChartLine,
  mdiChevronRight
} from '@mdi/js'

import {
  H4,
  H5,
  H6,
  Card,
  Body2,
  Caption,
  Subtitle2,
  IconButton,
  withResize,
  ToggleButton,
  ProgressCircular,
} from 'ui-neumorphism'

class Food extends React.Component {
  render() {
    const { dark, size } = this.props
    return (
      <Card flat dark={dark} className='fitness-app-container'>
        <Card flat className='fitness-app-wrapper overflow-hidden'>
          <Card
            rounded
            width={300}
            height={600}
            className={`fitness-app ${size === 'xs' ? 'fitness-app--small' : ''
              } overflow-hidden`}
          >
            <H4 style={{ fontWeight: '500', marginTop: '8px' }}>Food</H4>
            {/* Your changes here */}
            {/*  */}
            {/*  */}
            {/*  */}
            <div className='fitness-app-nav-bar'>
                <Link to="/">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiHome} size={0.9} />
                    </ToggleButton>
                </Link>
                <Link to="/program">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiChartLine} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/food">
                    <ToggleButton dark={dark} color='var(--primary)' selected>
                    <Icon path={mdiChartLine} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/todo">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiBell} size={0.8} />
                    </ToggleButton>
                </Link>
                <Link to="/accaunt">
                    <ToggleButton dark={dark}>
                    <Icon path={mdiAccount} size={0.9} />
                    </ToggleButton>
                </Link>
            </div>
          </Card>
        </Card>
        <Body2 style={{ marginTop: '48px', textAlign: 'center' }}>
        </Body2>
      </Card>
    )
  }
}

export default withResize(Food)